import QtQuick 1.1

import "../js/functions.js" as Functions

Rectangle {
    width: config.windowWidth
    height: config.windowHeight
    color: config.backgroundColor
    id: colorConfusion

    signal start
    signal finish
    signal showOptions
    signal showHighScores
    signal showIntro

    property int num_tries: config.numTries
    property int num_right: 0
    property int num_wrong: 0

    onStart: {
        intermission.focus = false
        intermission.visible = false
        high_scores.focus = false
        high_scores.visible = false
        select_set.focus = false
        select_set.visible = false
        intro.visible = false
        intro.focus = false

        color_to_guess.randomizeColor ()
        color_selector.mixAll ()
        timer_field.num_hundredth = 0
        num_tries = config.numTries
        num_right = 0
        num_wrong = 0

        game_widgets.visible = true
        game_widgets.focus = true
        timer_object.start()
    }

    onFinish: {
        if (num_wrong == 0) {
            bestScores.addScore(timer_field.num_hundredth)
        }

        timer_object.stop()
        game_widgets.focus = false
        game_widgets.visible = false
        intro.focus = false
        intro.visible = false

        intermission.visible = true
        intermission.focus = true

        if (num_wrong == 0) {
            intermission_text.color = config.winIntermissionColor
        } else {
            intermission_text.color = config.loseIntermissionColor
        }

        intermission_text.text = "Right answers: "
                + colorConfusion.num_right
                + "\nWrong answers: "
                + colorConfusion.num_wrong
                + "\nTotal time: "
                + Functions.getTimerText(timer_field.num_hundredth)

        if (bestScores.getScoresCount () > 0) {
            intermission_text.text = intermission_text.text
                    + "\nBest time: " + bestScores.getScoreValueAt(0)
        }
    }

    onShowOptions: {
        if (timer_object.running) {
            timer_object.stop()
        }
        intro.focus = false
        intro.visible = false
        select_set.resetModel ()
        select_set.visible = true
        select_set.focus = true
    }

    onShowHighScores: {
        if (timer_object.running) {
            timer_object.stop()
        }

        intermission.focus = false
        intermission.visible = false
        game_widgets.focus = false
        game_widgets.visible = false
        select_set.focus = false
        select_set.visible = false
        intro.focus = false
        intro.visible = false

        high_scores.resetModel ()
        high_scores.visible = true
        high_scores.focus = true
    }

    onShowIntro: {
        if (timer_object.running) {
            timer_object.stop()
        }
        intermission.focus = false
        intermission.visible = false
        high_scores.focus = false
        high_scores.visible = false
        game_widgets.focus = false
        game_widgets.visible = false
        select_set.focus = false
        select_set.visible = false

        intro.visible = true
        intro.focus = true
    }

    Column {
        id: game_widgets
        visible: false
        spacing: 10

        Keys.onEscapePressed: {
            colorConfusion.showIntro ()
        }

        Rectangle {
            property int num_hundredth: 0

            id: timer_field

            width: colorConfusion.width
            height: (colorConfusion.height - 20) / 12
            color: colorConfusion.color

            Text {
                id: timer_text
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                text: Functions.getTimerText(0)
            }

            Timer {
                id: timer_object
                interval: 10
                running: false
                repeat: true

                onTriggered: {
                    timer_field.num_hundredth += 1
                    timer_text.text = Functions.getTimerText(timer_field.num_hundredth)
                }
            }
        }

        ColorToGuess {
            width: colorConfusion.width
            height: (colorConfusion.height - 20) / 4

            id: color_to_guess

            onRightColor: {
                color_selector.disable (colorname)
                if (config.useAnimation) {
                    randomizeColorAnimated()
                } else {
                    randomizeColor()
                }

                colorConfusion.num_right++
                colorConfusion.num_tries--

                if (colorConfusion.num_tries <= 0) {
                    colorConfusion.finish ()
                }
            }

            onWrongColor: {
                color_selector.disable (colorname)
                colorConfusion.num_wrong++
            }

            onChangedColor: {
                color_selector.mixAll ()
                color_selector.enableAll ()
            }
        }

        ColorSelector {
            width: colorConfusion.width
            height: 2 * (colorConfusion.height - 20) / 3

            id: color_selector

            onMouseClick: {
                color_to_guess.tryColor (colorname)
            }
        }
    }

    Rectangle {
        id: intermission
        anchors.fill: parent
        visible: false
        color: colorConfusion.color

        Keys.onEscapePressed: {
            colorConfusion.showIntro ()
        }

        Text {
            id: intermission_text
            anchors.centerIn: parent
            font.pixelSize: parent.height / 15
            color: "black"
            text: ""
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                colorConfusion.showIntro ()
            }
        }
    }

    HighScores {
        id: high_scores
        visible: false
    }

    MyIntroduction {
        id: intro
        visible: true
        focus: true
    }

    ColorSetSelection {
        id: select_set
        visible: false
    }
}
