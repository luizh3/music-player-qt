import QtQuick 2.12
import QtGraphicalEffects 1.0
import QtQuick.Controls 2.1

Rectangle {
    id: root
    width: 250
    height: 350
    color: "transparent"

    signal addToQueue

    property string source: ""
    property string sourceMusic: ""

    property alias nameMusic: txtNameMusic.text
    property string artist: ""
    property string album: ""
    property string release: ""
    property string genre: ""

    Rectangle {
        id: rectangleMusic
        width: root.width
        height: root.height / 1.7
        color: "#7d7d7d"
        radius: 3
        visible: true

        Column {
            width: parent.width
            height: parent.height / 1.2
            anchors.centerIn: parent
            spacing: 10

            Rectangle {
                id: imgRectangle
                color: "transparent"
                width: parent.width / 1.2
                height: parent.height / 1.2
                anchors.horizontalCenter: parent.horizontalCenter

                RectangularGlow {
                    anchors.fill: imgMusic
                    glowRadius: 20
                    cornerRadius: 25
                    spread: 0.0
                    color: "#000"
                    opacity: 0.7
                    visible: imgMusic.visible
                }

                Image {
                    id: imgMusic
                    source: root.source
                    width: parent.width
                    height: parent.height
                    fillMode: Image.PreserveAspectCrop
                    layer.enabled: true
                    anchors.verticalCenter: parent.verticalCente

                    layer.effect: OpacityMask {
                        maskSource: rectangleMaskImg
                    }
                }

                Rectangle {
                    id: rectangleMaskImg
                    width: imgMusic.width
                    height: imgMusic.height
                    color: "#fff"
                    radius: 5
                    visible: false
                }
            }

            TextMetrics {
                id: textMetrics
                font.family: "Arial"
                elide: Text.ElideRight
                elideWidth: 125 // TODO change for a dynamic width
                text: root.nameMusic
            }

            Text {
                text: textMetrics.elidedText
                anchors.horizontalCenter: parent.horizontalCenter
                color: "#fff"
                font.pixelSize: 18
            }
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true
        }
    }

    RectangularGlow {
        id: effectShadow
        anchors.fill: rectangleMusicFocus
        glowRadius: 20
        cornerRadius: 25
        spread: 0.0
        color: "#000"
        opacity: 0.7
        visible: rectangleMusicFocus.visible
    }

    Rectangle {
        id: rectangleMusicFocus
        width: root.width
        height: root.height
        color: "#0f171e"
        radius: 3
        visible: mouseArea.containsMouse
                 || mouseAreaDescricaoMusic.containsMouse
        anchors.top: rectangleMusic.top
        anchors.left: rectangleMusic.left

        MouseArea {
            id: mouseAreaDescricaoMusic
            anchors.fill: parent
            hoverEnabled: true
        }

        Column {
            width: parent.width
            height: parent.height
            spacing: 10

            Rectangle {
                id: rectangleImgOnFocus
                width: parent.width
                height: parent.height / 2.5
                color: "transparent"

                Image {
                    id: imgContainsMouse
                    source: root.source
                    width: parent.width
                    height: parent.height
                    fillMode: Image.PreserveAspectCrop
                    layer.enabled: true
                    layer.effect: OpacityMask {
                        maskSource: rectangleMaskImg
                    }
                }

                Rectangle {
                    width: parent.width
                    height: 4
                    anchors.bottom: parent.bottom
                    color: "#0f171e"
                    radius: 0
                }

                Rectangle {
                    id: rectangleMaskImgContainsMouse
                    width: parent.width
                    height: parent.height
                    radius: 5
                    visible: false
                }
            }

            Row {
                id: rowPlay
                width: parent.width / 1.1
                height: 50
                spacing: 10
                anchors.horizontalCenter: parent.horizontalCenter

                Rectangle {
                    width: 40
                    height: 40
                    radius: 360
                    color: mouseAreaPlay.containsMouse ? "#3db0f7" : "#0f171e"
                    border.color: mouseAreaPlay.containsMouse ? "#3db0f7" : "#fff"
                    anchors.verticalCenter: parent.verticalCenter

                    Behavior on color {
                        ColorAnimation {
                            duration: 150
                        }
                    }

                    Behavior on border.color {
                        ColorAnimation {
                            duration: 150
                        }
                    }

                    Image {
                        width: 15
                        height: 15
                        source: "../img/play.png"
                        anchors.centerIn: parent
                    }

                    MouseArea {
                        id: mouseAreaPlay
                        anchors.fill: parent
                        hoverEnabled: true

                        onClicked: {
                            root.addToQueue()
                        }
                    }
                }

                Text {
                    text: "Reproduzir"
                    font.pointSize: 16
                    color: "#fff"
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            MoreOptions {
                anchors.right: parent.right
                anchors.rightMargin: 20
                anchors.verticalCenter: parent.verticalCenter
                closePolicy: !(mouseArea.containsMouse
                               || mouseAreaDescricaoMusic.containsMouse)
                onAddToQueue: {
                    root.addToQueue()
                }
                z: 3
            }

            Column {
                width: parent.width / 1.1
                height: parent.height - (rectangleImgOnFocus.height + rowPlay.height)
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 5

                Text {
                    id: txtNameMusic
                    text: "A Real Hero"
                    color: "#3db0f7"
                    font.pointSize: 14
                    elide: Text.ElideRight
                    width: parent.width
                }

                Text {
                    id: txtArtist
                    text: "Artista: " + root.artist
                    color: "#fff"
                    font.pointSize: 11
                }

                Text {
                    id: txtAlbum
                    text: "Álbum: " + root.album
                    color: "#fff"
                    font.pointSize: 11
                }

                Text {
                    id: txtGenre
                    text: "Gênero: " + root.genre
                    color: "#fff"
                    font.pointSize: 11
                }

                Text {
                    id: txtDateRelease
                    text: "Data de lançamento: " + root.release
                    color: "#fff"
                    font.pointSize: 11
                }
            }
        }
    }
}
