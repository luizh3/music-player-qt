import QtQuick 2.0
import QtMultimedia 5.0
import QtQuick.Controls 2.1

import "components/music"

import br.com.musiccontroller 1.0

Rectangle {

    id: root
    height: 100
    anchors.bottom: parent.bottom
    anchors.right: parent.right

    property MediaPlayer mediaPlayer: MediaPlayer {}
    property QtObject currentMusic: QtObject {
        property string sourceImage: "/img/music/unknow.jpg"
        property string nameMusic: "unknow"
        property string album: "unknow"
    }

    property MusicController musicController: MusicController {
        onCurrentMusicChange: function (music) {
            root.currentMusic = music
            mediaPlayer.source = music.sourceMusic
            mediaPlayer.play()
        }
    }

    signal addMusicQueue(var music)

    onAddMusicQueue: function (music) {
        musicController.addMusicQueue(music)

        if (mediaPlayer.playbackState === MediaPlayer.StoppedState) {
            musicController.start()
        }
    }

    color: "#121212"

    PreviewMusic {
        musicObject: currentMusic
    }

    Column {
        width: root.width
        height: root.height / 1.5
        anchors.verticalCenter: parent.verticalCenter

        Row {
            width: root.width
            height: root.height / 2.8

            Row {
                width: childrenRect.width
                anchors.right: parent.right
                anchors.rightMargin: 20
                spacing: 10

                AudioControl {
                    width: 100
                    height: 50
                    mediaPlayer: root.mediaPlayer
                }

                PlayBackRateControl {
                    width: 133
                    height: 30
                    mediaPlayer: root.mediaPlayer
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            Row {
                width: childrenRect.width
                height: parent.height
                anchors.horizontalCenter: parent.horizontalCenter

                RoundButton {
                    radius: 50.0
                    width: 40
                    height: 40
                    icon.width: 20
                    icon.height: 20
                    icon.source: "/img/rewind.png"
                    anchors.verticalCenter: parent.verticalCenter
                    onClicked: {
                        musicController.previous()
                    }
                }

                RoundButton {
                    id: pauseOrPlayButton
                    radius: 50.0
                    icon.width: 20
                    icon.height: 20
                    anchors.verticalCenter: parent.verticalCenter
                    icon.source: mediaPlayer.playbackState
                                 == MediaPlayer.PlayingState ? "/img/pause.png" : "/img/play.png"
                    onClicked: {
                        if (mediaPlayer.playbackState == MediaPlayer.PlayingState) {
                            mediaPlayer.pause()
                        } else {
                            mediaPlayer.play()
                        }
                    }
                }

                RoundButton {
                    radius: 50.0
                    width: 40
                    height: 40
                    icon.width: 20
                    icon.height: 20
                    icon.source: "/img/next.png"
                    anchors.verticalCenter: parent.verticalCenter
                    onClicked: {
                        musicController.next()
                    }
                }
            }
        }

        Row {
            width: root.width
            height: parent.height / 1.3
            anchors.horizontalCenter: parent.horizontalCenter

            DurationMusicControl {
                width: parent.width / 1.8
                height: parent.height / 2
                mediaPlayer: root.mediaPlayer
                anchors.left: parent.left
                anchors.leftMargin: ((parent.width - width) / 2) - 15
            }
        }
    }
}
