import QtQuick 2.0

import "../components/openfile"

Rectangle {
    id: root
    color: "#1C1C1C"
    width: root.open ? root.sizeOpen : root.minimumWidth
    anchors.left: parent.left

    signal urlMusic(var url)
    signal queueMusicsPressed
    signal inicioPressed
    signal effectsPressed
    signal animatedSpacePressed

    property bool open: false
    property int minimumWidth: 60
    property int maximumWidth: 60
    property int sizeOpen: root.maximumWidth / 4

    Behavior on width {
        NumberAnimation {
            duration: 75
        }
    }

    MouseArea {
        hoverEnabled: true
        anchors.fill: parent
    }

    Column {
        width: parent.width
        height: parent.height
        anchors.top: parent.top
        spacing: 10

        ButtonIcon {
            width: root.open ? sizeOpen : root.minimumWidth
            height: 50
            source: "../img/menu.png"
            visibleDescription: root.open
            colorPressed: "#3688eb"
            onClicked: {
                root.open = !root.open
            }
        }

        ButtonIcon {
            id: buttonHome
            width: root.open ? root.sizeOpen : root.minimumWidth
            height: 50
            source: "../img/home.png"
            textDescription: "Início"
            colorPressed: "#3688eb"
            visibleDescription: root.open
            onClicked: root.inicioPressed()
        }

        ButtonIcon {
            id: buttonStop
            width: root.open ? root.sizeOpen : root.minimumWidth
            height: 50
            source: "../img/biblioteca.png"
            anchors.left: parent.left
            textDescription: "Biblioteca"
            visibleDescription: root.open
            colorPressed: "#3688eb"
        }

        ButtonIcon {
            id: buttonEffects
            width: root.open ? root.sizeOpen : root.minimumWidth
            height: 50
            source: "../img/skimming.png"
            anchors.left: parent.left
            textDescription: "Effects"
            visibleDescription: root.open
            colorPressed: "#3688eb"
            onClicked: root.effectsPressed()
        }

        ButtonIcon {
            id: buttonOpenFile
            width: root.open ? root.sizeOpen : root.minimumWidth
            height: 50
            source: "../img/filepath.png"
            textDescription: "Open music"
            colorPressed: "#3688eb"
            visibleDescription: root.open
            onClicked: {
                var newObject = Qt.createQmlObject(
                            'import "../components/openfile"; OpenFile{ onUrl:function( textUrl ){ root.urlMusic( textUrl ) }}',
                            root)
                newObject.open()
            }
        }

        ButtonIcon {
            id: queueMusics
            width: root.open ? root.sizeOpen : root.minimumWidth
            height: 50
            source: "../img/queue.png"
            anchors.left: parent.left
            textDescription: "Fila"
            visibleDescription: root.open
            colorPressed: "#3688eb"
            onClicked: root.queueMusicsPressed()
        }

        ButtonIcon {
            id: animatedSpace
            width: root.open ? root.sizeOpen : root.minimumWidth
            height: 50
            source: "../img/calma.png"
            anchors.left: parent.left
            textDescription: "Animated Space"
            visibleDescription: root.open
            colorPressed: "#3688eb"
            onClicked: root.animatedSpacePressed()
        }
    }
}
