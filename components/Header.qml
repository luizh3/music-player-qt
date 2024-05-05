import QtQuick 2.0

import "../components"

Rectangle {
    id: header
    width: parent.width
    height: 50
    color: "#121212"
    visible: true
    z: 1

    Row {
        width: childrenRect.width
        height: parent.height
        anchors.right: parent.right
        anchors.rightMargin: 20
        spacing: 10

        ButtonIcon {
            width: 50
            height: 40
            source: "/img/minimize.png"
            colorDefault: "#121212"
            colorPressedIcon: "#000"
            radius: 3
            heightImg: 20
            widthImg: 20
            anchors.verticalCenter: parent.verticalCenter
            visibleDescription: false
            onClicked: {
                showMinimized()
            }
        }

        ButtonIcon {
            width: 50
            height: 40
            source: "/img/quadrado.png"
            colorDefault: "#121212"
            colorPressedIcon: "#000"
            radius: 3
            heightImg: 20
            widthImg: 20
            anchors.verticalCenter: parent.verticalCenter
            visibleDescription: false
            onClicked: {
                changeVisibleMode()
            }
        }

        ButtonIcon {
            width: 50
            height: 40
            source: "/img/x.png"
            colorDefault: "#121212"
            colorPressed: "#ff4040"
            radius: 3
            heightImg: 20
            widthImg: 20
            anchors.verticalCenter: parent.verticalCenter
            visibleDescription: false
            onClicked: {
                close()
            }
        }
    }
}
