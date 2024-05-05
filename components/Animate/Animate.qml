import QtQuick 2.0
import QtQml 2.1
import QtGraphicalEffects 1.0

Rectangle {
    id: root

    property string currentSource: "../../img/animate/thirt.gif"
    property var resources: ["../../img/animate/thirt.gif", "../../img/animate/second.gif", "../../img/animate/first.gif"]

    property QtObject imageSelected: ImagePreview {}

    Rectangle {
        width: 120
        height: 380
        radius: 20
        border.color: "#121212"
        color: "#121212"
        anchors.left: parent.left
        anchors.leftMargin: 30
        anchors.verticalCenter: parent.verticalCenter
        z: 2

        Column {
            width: parent.width
            height: parent.height
            spacing: 10

            Flickable {
                id: flickable
                width: parent.width
                height: parent.height / 1.4
                contentHeight: columnFlickable.height
                clip: true

                Column {
                    id: columnFlickable
                    width: parent.width
                    anchors.top: parent.top
                    anchors.topMargin: 10
                    spacing: 10

                    Repeater {
                        id: repeater
                        model: root.resources

                        ImagePreview {
                            id: imagePreview
                            source: modelData

                            function changeCurrentImage() {
                                root.imageSelected.selected = false
                                root.imageSelected = imagePreview
                                root.imageSelected.selected = true
                            }

                            Component.onCompleted: {
                                if (index === 0) {
                                    changeCurrentImage()
                                }
                            }

                            onClicked: {
                                changeCurrentImage()
                                root.currentSource = imagePreview.source
                            }
                        }
                    }
                }
            }

            Rectangle {
                width: 100
                height: 80
                border.color: "#bebebe"
                color: "transparent"
                border.width: 1
                radius: 20
                anchors.horizontalCenter: parent.horizontalCenter

                Image {
                    id: img
                    width: 36
                    height: 36
                    source: "../../img/plus.png"
                    anchors.centerIn: parent
                }
            }
        }
    }

    AnimatedImage {
        id: animation
        source: root.currentSource
        anchors.fill: parent
        z: 1
    }
}
