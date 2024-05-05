import QtQuick 2.0
import QtGraphicalEffects 1.0

Rectangle {
    id: root
    width: 100
    height: 80
    color: "transparent"
    radius: 20
    anchors.horizontalCenter: parent.horizontalCenter

    property string source: ""
    property bool selected: false

    signal clicked

    MouseArea {
        id: mouseArea
        hoverEnabled: true
        anchors.fill: parent

        onClicked: {
            root.clicked()
        }
    }

    AnimatedImage {
        source: modelData
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
        layer.enabled: true
        playing: false

        layer.effect: OpacityMask {
            maskSource: rectangleSelected
        }
    }

    Rectangle {
        id: rectangleSelected
        anchors.fill: parent
        color: "#3688eb"
        opacity: 0.6
        visible: root.selected
        radius: root.radius
    }

    Image {
        id: img
        width: 36
        height: 36
        source: "../../img/check.png"
        anchors.centerIn: rectangleSelected
        visible: rectangleSelected.visible
    }
}
