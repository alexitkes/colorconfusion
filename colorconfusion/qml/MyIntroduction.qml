import QtQuick 1.1

Rectangle {
    anchors.fill: parent
    color: colorConfusion.color

    Keys.onReturnPressed: {
        colorConfusion.start ()
    }

    Keys.onEscapePressed: {
        Qt.quit()
    }

    Column {
        anchors.fill: parent
        spacing: 10

        Rectangle {
            width: intro.width
            height: (intro.height - 30) / 8
            color: colorConfusion.color

            Text {
                anchors.centerIn: parent
                font.pixelSize: parent.height / 2
                color: "Black"
                text: "Welcome to ColorConfusion"
            }
        }

        Rectangle {
            width: intro.width
            height: 5 * (intro.height - 30) / 8
            color: colorConfusion.color

            Text {
                anchors.centerIn: parent
                font.pixelSize: parent.height / 20
                color: "Black"
                text: "Short instruction to be written here"
            }
        }

        Grid {
            rows: 2
            columns: 3
            spacing: 10

            MyButton {
                id: button_start
                width: (intro.width - 20) / 3
                height: (intro.height - 20) / 8
                text_color: "Black"
                background_color: colorConfusion.color
                fontsize: height / 4
                text: "Start"

                onClicked: {
                    colorConfusion.start ()
                }
            }

            MyButton {
                id: button_options
                width: (intro.width - 20) / 3
                height: (intro.height - 30) / 8
                text_color: "Black"
                background_color: colorConfusion.color
                fontsize: height / 4
                text: "Options"

                onClicked: {
                    colorConfusion.showOptions ()
                }
            }

            MyButton {
                id: button_highscores
                width: (intro.width - 20) / 3
                height: (intro.height - 30) / 8
                text_color: "Black"
                background_color: colorConfusion.color
                fontsize: height / 4
                text: "Best scores"

                onClicked: {
                    colorConfusion.showHighScores ()
                }
            }

            MyButton {
                id: button_graph
                width: (intro.width - 20) / 3
                height: (intro.height - 30) / 8
                text_color: "Black"
                background_color: colorConfusion.color
                fontsize: height / 4
                text: "Graph"

                onClicked: {
                    text = "Graph\n[Not implemented]"
                }
            }

            MyButton {
                id: button_help
                width: (intro.width - 20) / 3
                height: (intro.height - 30) / 8
                text_color: "Black"
                background_color: colorConfusion.color
                fontsize: height / 4
                text: "Help"

                onClicked: {
                    text = "Help\n[Not implemented]"
                }
            }

            MyButton {
                id: button_quit
                width: (intro.width - 20) / 3
                height: (intro.height - 30) / 8
                text_color: "Black"
                background_color: colorConfusion.color
                fontsize: height / 4
                text: "Quit"

                onClicked: {
                    Qt.quit()
                }
            }
        }
    }
}
