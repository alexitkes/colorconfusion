import QtQuick 1.1

import "../js/functions.js" as Functions

Rectangle {
    property string colortext_value: "black"
    property color colortext_color: "black"

    signal mouseClicked

    color: colorConfusion.color
    state: "enabled"
    id: main

    Rectangle {
        border.color: parent.colortext_color
        border.width: 5
        id: text_area
        anchors.fill: parent
        color: colorConfusion.color

        Text {
            anchors.centerIn: parent
            text: Functions.getColorAlias(parent.parent.colortext_value)
            color: parent.border.color
            font.pixelSize: parent.height / 3
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (parent.state == "enabled") {
                parent.mouseClicked ()
            }
        }
    }

    states: [
        State {
            name: "enabled"
            PropertyChanges {
                target: text_area
                border.color: main.colortext_color
            }
        },
        State {
            name: "disabled"
            PropertyChanges {
                target: text_area
                border.color: config.disabledColor
            }
        }
    ]
}
