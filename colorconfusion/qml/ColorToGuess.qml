import QtQuick 1.1

import "../js/functions.js" as Functions

Rectangle {
    width: 640
    height: 100
    color: colorConfusion.color

    Rectangle {
        anchors.centerIn: parent
        width: parent.width
        height: parent.height
        id: parent_rect
        color: colorConfusion.color

        ParallelAnimation {
            id: shrink_animation
            running: false

            NumberAnimation {
                target: parent_rect
                property: "x"
                duration: 150
                from: 0
                to: parent_rect.parent.width / 2
            }

            NumberAnimation {
                target: parent_rect
                property: "y"
                duration: 150
                from: 0
                to: parent_rect.parent.height / 2
            }

            NumberAnimation {
                target: parent_rect
                property: "width"
                duration: 150
                from: parent_rect.parent.width
                to: 0
            }

            NumberAnimation {
                target: parent_rect
                property: "height"
                duration: 150
                from: parent_rect.parent.height
                to: 0
            }

            onCompleted: {
                randomizeColor()
                grow_animation.start()
            }
        }

        ParallelAnimation {
            id: grow_animation
            running: false

            NumberAnimation {
                target: parent_rect
                property: "x"
                duration: 150
                from: parent_rect.parent.width / 2
                to: 0
            }

            NumberAnimation {
                target: parent_rect
                property: "y"
                duration: 150
                from: parent_rect.parent.height / 2
                to: 0
            }

            NumberAnimation {
                target: parent_rect
                property: "width"
                duration: 150
                from: 0
                to: parent_rect.parent.width
            }

            NumberAnimation {
                target: parent_rect
                property: "height"
                duration: 150
                from: 0
                to: parent_rect.parent.height
            }
        }

        border.width: 5
        border.color: parent.color_value

        Text {
            anchors.centerIn: parent
            color: parent.parent.color_value
            text: Functions.getColorAlias(parent.parent.color_text)
            font.pixelSize: parent.height / 3
        }
    }

    property string color_text: "black"
    property string color_name: "black"
    property color color_value: "black"

    signal randomizeColor
    signal randomizeColorAnimated
    signal tryColor (string colorname)
    signal rightColor (string colorname)
    signal wrongColor (string colorname)
    signal changedColor

    onRandomizeColor: {
        var name = Functions.getRandomColor()
        var value = Functions.getRandomColor()

        color_text = name
        color_name = value
        color_value = value

        changedColor()
    }

    onRandomizeColorAnimated: {
        shrink_animation.start()
    }

    onTryColor: {
        if (colorname == color_name) {
            rightColor(colorname)
        } else {
            wrongColor(colorname)
        }
    }
}
