import QtQuick 1.1

Rectangle {
    property color background_color: "white"
    property color text_color: "black"
    property string text: ""
    property int fontsize

    signal clicked
    signal colorConfusionColorChanged

    color: background_color
    border.width: 2
    state: "unhovered"
    id: main_rect

    states: [
        State {
            name: "unhovered"
            PropertyChanges {
                target: the_text
                font.pixelSize: main_rect.fontsize
            }
            PropertyChanges {
                target: main_rect
                border.color: background_color
            }
        },
        State {
            name: "hovered"
            PropertyChanges {
                target: the_text
                font.pixelSize: main_rect.fontsize + main_rect.fontsize / 3
            }
            PropertyChanges {
                target: main_rect
                border.color: text_color
            }
        },
        State {
            name: "pressed"
            PropertyChanges {
                target: main_rect
                color: "white"
                border.color: text_color
            }
            PropertyChanges {
                target: the_text
                font.pixelSize: main_rect.fontsize + main_rect.fontsize / 4
            }
        }
    ]

    transitions: [
        Transition {
            from: "*"
            to: "*"
            PropertyAnimation {
                target: the_text;
                property: "font.pixelsize"
                duration: 50
            }
        }
    ]

    Text {
        id: the_text
        anchors.centerIn: parent
        text: parent.text
        font.pixelSize: parent.fontsize
        color: parent.text_color
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true

        onClicked: {
            parent.clicked ()
        }
        onEntered: {
            parent.state = "hovered"
        }
        onExited: {
            parent.state = "unhovered"
        }
        onPressed: {
            parent.state = "pressed"
        }
        onReleased: {
            parent.state = "hovered"
        }
    }
}
