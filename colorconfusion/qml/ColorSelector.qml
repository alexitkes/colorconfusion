import QtQuick 1.1

import "../js/functions.js" as Functions

Rectangle {
    color: colorConfusion.color
    width: 640
    height: 480

    Grid {
        rows: 3
        columns: 2
        spacing: 10

        ColorChoice {
            width: (parent.parent.width - 10) / 2
            height: (parent.parent.height - 20) / 3
            id: first_choice

            onMouseClicked: {
                parent.parent.mouseClick (colortext_value)
            }
        }

        ColorChoice {
            width: (parent.parent.width - 10) / 2
            height: (parent.parent.height - 20) / 3
            id: second_choice

            onMouseClicked: {
                parent.parent.mouseClick (colortext_value)
            }
        }

        ColorChoice {
            width: (parent.parent.width - 10) / 2
            height: (parent.parent.height - 20) / 3
            id: third_choice

            onMouseClicked: {
                parent.parent.mouseClick (colortext_value)
            }
        }

        ColorChoice {
            width: (parent.parent.width - 10) / 2
            height: (parent.parent.height - 20) / 3
            id: fourth_choice

            onMouseClicked: {
                parent.parent.mouseClick (colortext_value)
            }
        }

        ColorChoice {
            width: (parent.parent.width - 10) / 2
            height: (parent.parent.height - 20) / 3
            id: fifth_choice

            onMouseClicked: {
                parent.parent.mouseClick (colortext_value)
            }
        }

        ColorChoice {
            width: (parent.parent.width - 10) / 2
            height: (parent.parent.height - 20) / 3
            id: sixth_choice

            onMouseClicked: {
                parent.parent.mouseClick (colortext_value)
            }
        }
    }

    signal mixAll
    signal enableAll
    signal disable (string colorname)
    signal mouseClick (string colorname)

    onMixAll: {
        var a = Functions.getRandomArrangement()
        var b = Functions.getRandomArrangement()

        first_choice.colortext_color = a [0]
        first_choice.colortext_value = b [0]
        second_choice.colortext_color = a [1]
        second_choice.colortext_value = b [1]
        third_choice.colortext_color = a [2]
        third_choice.colortext_value = b [2]
        fourth_choice.colortext_color = a [3]
        fourth_choice.colortext_value = b [3]
        fifth_choice.colortext_color = a [4]
        fifth_choice.colortext_value = b [4]
        sixth_choice.colortext_color = a [5]
        sixth_choice.colortext_value = b [5]
    }

    onEnableAll: {
        first_choice.state = "enabled"
        second_choice.state = "enabled"
        third_choice.state = "enabled"
        fourth_choice.state = "enabled"
        fifth_choice.state = "enabled"
        sixth_choice.state = "enabled"
    }

    onDisable: {
        if (first_choice.colortext_value == colorname) {
            first_choice.state = "disabled"
        }
        if (second_choice.colortext_value == colorname) {
            second_choice.state = "disabled"
        }
        if (third_choice.colortext_value == colorname) {
            third_choice.state = "disabled"
        }
        if (fourth_choice.colortext_value == colorname) {
            fourth_choice.state = "disabled"
        }
        if (fifth_choice.colortext_value == colorname) {
            fifth_choice.state = "disabled"
        }
        if (sixth_choice.colortext_value == colorname) {
            sixth_choice.state = "disabled"
        }
    }

    onMouseClick: {
        disable(colorname)
    }
}
