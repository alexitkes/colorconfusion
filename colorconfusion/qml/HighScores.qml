import QtQuick 1.1

import "../js/functions.js" as Functions

Rectangle {
    anchors.fill: parent
    color: colorConfusion.color

    signal resetModel

    Keys.onPressed: {
        if (event.key == Qt.Key_Home) {
            list_view.positionViewAtBeginning()
        } else if (event.key == Qt.Key_End) {
            list_view.positionViewAtEnd()
        } else if (event.key == Qt.Key_Up) {
            list_view.contentY -= 8
            if (list_view.visibleArea.yPosition < 0) {
                list_view.positionViewAtBeginning();
            }
        } else if (event.key == Qt.Key_Down) {
            list_view.contentY += 8
            if (list_view.visibleArea.yPosition > 1 - list_view.visibleArea.heightRatio) {
                list_view.positionViewAtEnd();
            }
        } else if (event.key == Qt.Key_PageUp) {
            list_view.contentY -= (list_view.height - 8)
            if (list_view.visibleArea.yPosition < 0) {
                list_view.positionViewAtBeginning();
            }
        } else if (event.key == Qt.Key_PageDown) {
            list_view.contentY += (list_view.height - 8)
            if (list_view.visibleArea.yPosition > 1 - list_view.visibleArea.heightRatio) {
                list_view.positionViewAtEnd();
            }
        }
    }

    onResetModel: {
        var i, count

        scores_list.clear()

        count = bestScores.getScoresCount()

        for (i = 0; i < count; i++) {
            scores_list.append({"num": i + 1, "value": bestScores.getScoreValueAt(i), "timestamp": bestScores.getDateTimeValueAt(i)})
        }
    }

    Keys.onEscapePressed: {
        colorConfusion.showIntro ()
    }

    ListModel {
        id: scores_list
    }

    ListView {
        anchors.fill: parent
        id: list_view
        model: scores_list
        header: Rectangle {
            width: parent.width
            height: 32
            color: colorConfusion.color

            Text {
                anchors.centerIn: parent
                color: "black"
                text: "Best results"
            }
        }
        footer: Rectangle {
            width: parent.width
            height: 12
            color: colorConfusion.color
        }
        delegate: Rectangle {
            width: parent.width
            height: 40
            color: colorConfusion.color

            Column {
                anchors.centerIn: parent
                spacing: 4

                Rectangle {
                    width: parent.width
                    height: 24
                    Text {
                        anchors.centerIn: parent
                        color: "black"
                        text: "#" + num + ".  " + value
                        font.pixelSize: 20
                    }
                }
                Rectangle {
                    width: parent.width
                    height: 12
                    Text {
                        anchors.centerIn: parent
                        color: "black"
                        text: "Achieved at: " + timestamp
                        font.pixelSize: 10
                    }
                }
            }
        }
        flickableDirection: Flickable.VerticalFlick
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            colorConfusion.showIntro ()
        }
    }
}
