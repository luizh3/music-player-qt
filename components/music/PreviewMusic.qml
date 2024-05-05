import QtQuick 2.0
import QtQuick.Controls 2.0

Rectangle {
    width: 200
    height: 50
    color: "transparent"
    anchors.verticalCenter: parent.verticalCenter

    property QtObject musicObject

    Row {
        width: parent.width
        height: parent.height
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.verticalCenter: parent.verticalCenter
        spacing: 5

        Image {
            id: imageCurrentMusic
            source: musicObject.sourceImage
            width: 50
            height: parent.height
            fillMode: Image.PreserveAspectCrop
        }
        Column {
            width: parent.width
            anchors.verticalCenter: parent.verticalCenter
            spacing: 1

            Text {
                width: parent.width
                text: musicObject.nameMusic
                font.pixelSize: 16
                color: "#fff"
                elide: Text.ElideRight
            }
            Text {
                text: musicObject.album
                font.pixelSize: 13
                color: "#bebebe"
            }
        }
    }
}
