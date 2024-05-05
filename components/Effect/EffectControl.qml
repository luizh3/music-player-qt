import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0

import "../"

Rectangle {
    id: root
    width: 0
    height: parent.height
    color: "#232323"

    property int widthCustom: 300

    states: [
        State {
            name: "widthExpand"
            when: root.visible
            PropertyChanges {
                target: root
                width: widthCustom
            }
        }
    ]

    Behavior on width {
        NumberAnimation {
            duration: 100
        }
    }

    MouseArea {
        hoverEnabled: true
        anchors.fill: parent
    }

    ButtonIcon {
        width: 40
        height: 40
        source: "../../img/x.png"
        colorDefault: "transparent"
        colorPressed: "transparent"
        colorDefaultIcon: "#fff"
        colorPressedIcon: "#ff4040"
        heightImg: height / 2
        widthImg: width / 2
        visibleDescription: false
        anchors {
            top: root.top
            right: root.right
            rightMargin: 15
            topMargin: 5
        }
        onClicked: {
            root.visible = false
        }
    }

    Column {
        width: parent.width / 1.1
        height: parent.height / 1.1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        EffectButton {
            sourceIcon: "../../img/effects/chuva.png"
            sourceSong: "../../music/rain.mp3"
            width: parent.width / 3
            height: 50
        }

        EffectButton {
            sourceIcon: "../../img/effects/fogo.png"
            sourceSong: "../../music/fogueira.mp3"
            width: parent.width / 3
            height: 50
        }

        EffectButton {
            sourceIcon: "../../img/effects/vento.png"
            sourceSong: "../../music/vento.mp3"
            width: parent.width / 3
            height: 50
        }
    }
}
