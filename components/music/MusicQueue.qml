import QtQuick 2.0
import QtQuick.Controls 2.0

import br.com.musiccontroller 1.0

Rectangle {
    id: root
    color: "transparent"

    property MusicController musicController
    property var musicas: musicController.nextMusics

    property bool hasMusica: musicas.length > 0

    Flickable {
        width: parent.width
        height: parent.height
        contentHeight: childrenRect.height
        clip: true

        Column {
            width: parent.width / 1.05
            height: parent.height
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 10

            Label {
                text: root.hasMusica ? "Fila" : "Nenhuma música na fila"
                font.pointSize: 20
                color: "#fff"
                font.bold: true
            }

            Column {
                width: parent.width
                spacing: 10
                visible: root.hasMusica

                Label {
                    font.pointSize: 14
                    text: "Tocando agora"
                    color: "gray"
                }

                Rectangle {
                    width: parent.width
                    color: mouseAreaMusicPlaying.containsMouse ? "#2e2d2d" : "transparent"
                    height: 70
                    radius: 3

                    MouseArea {
                        id: mouseAreaMusicPlaying
                        hoverEnabled: true
                        anchors.fill: parent
                    }

                    PreviewMusic {
                        musicObject: musicController.currentMusic
                    }
                }
            }

            Column {
                width: parent.width
                spacing: 10
                visible: repeater.model.length > 0

                Label {
                    font.pointSize: 14
                    text: "Próxima na fila"
                    color: "gray"
                }

                Repeater {
                    id: repeater
                    model: {
                        var queue = [...musicas]
                        queue.splice(0, 1)
                        return queue
                    }

                    Rectangle {
                        width: parent.width
                        color: mouseArea.containsMouse ? "#2e2d2d" : "transparent"
                        height: 70
                        radius: 3
                        anchors.horizontalCenter: parent.horizontalCenter

                        MouseArea {
                            id: mouseArea
                            hoverEnabled: true
                            anchors.fill: parent
                        }

                        PreviewMusic {
                            musicObject: modelData
                        }
                    }
                }
            }
        }
    }
}
