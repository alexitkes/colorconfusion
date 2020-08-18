import QtQuick 1.1

Rectangle {
    color: colorConfusion.color
    anchors.fill: parent

    signal resetModel

    onResetModel: {
        qml_colorsetsModel.clear()

        var list = config.listColorSets()
        var i

        for (i = 0; i < list.length; i++) {
            qml_colorsetsModel.append({"display": list [i]})
        }
    }

    Keys.onEscapePressed: {
        colorConfusion.showIntro ()
    }

    ListModel {
        id: qml_colorsetsModel
    }

    ListView {
        anchors.fill: parent

        model: qml_colorsetsModel
        header: Rectangle {
            width: parent.width
            height: 32
            color: colorConfusion.color

            Text {
                anchors.centerIn: parent
                color: "black"
                text: "Choose color set to play"
            }
        }
        footer: Rectangle {
            width: parent.width
            height: 12
            color: colorConfusion.color
        }
        delegate: Rectangle {
            width: parent.width
            height: 32
            color: colorConfusion.color
            border.width: 1
            border.color: "black"

            Text {
                anchors.centerIn: parent
                color: "black"
                text: display
            }

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true

                onClicked: {
                    config.chooseColorSet (display)

                    colorConfusion.showIntro ()
                }

                onEntered: parent.color = "white"
                onExited: parent.color = colorConfusion.color
            }
        }
    }
}
