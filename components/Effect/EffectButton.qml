import QtQuick 2.0
import QtQuick.Controls 2.0
import QtMultimedia 5.0

import "../music"

Row {
    spacing: 5

    property alias sourceIcon: image.source
    property alias sourceSong: mediaPlayer.source

    MediaPlayer {
        id: mediaPlayer
        autoLoad: true
        loops: MediaPlayer.Infinite
    }

    Button {
        id: button
        width: parent.width / 2
        height: parent.height

        property bool isEnableSong: false

        background: Rectangle {
            color: button.isEnableSong ? "#3688eb" : "#3a4055"
            radius: 4
        }

        Image {
            id: image
            width: parent.width / 1.4
            height: parent.height / 1.4
            anchors.centerIn: parent
        }

        onClicked: {

            button.isEnableSong = !button.isEnableSong

            if (mediaPlayer.playbackState == MediaPlayer.PlayingState) {
                mediaPlayer.pause()
            } else {
                mediaPlayer.play()
            }
        }
    }

    AudioControl {
        id: audioControl
        width: parent.width
        height: parent.height
        mediaPlayer: mediaPlayer
    }
}
