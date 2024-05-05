import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtMultimedia 5.0

Item {
    id: root

    property MediaPlayer mediaPlayer
    property bool muted: false
    property real volume: volumeSlider.value / 100
    property real lastValue: 0.0

    onVolumeChanged: {
        mediaPlayer.volume = root.volume
    }

    onMutedChanged: {
        mediaPlayer.muted = root.muted
    }

    RowLayout {
        anchors.fill: parent
        spacing: 0

        Button {
            id: muteButton
            background: Rectangle {
                color: "transparent"
            }
            icon.color: "#fff"
            implicitWidth: 40
            implicitHeight: 40
            icon.source: muted ? "/img/volume-muted.png" : "/img/volume.png"
            onClicked: {
                muted = !muted

                if (muted) {
                    root.lastValue = volumeSlider.value
                    volumeSlider.value = 0
                } else {
                    volumeSlider.value = root.lastValue
                }
            }
        }

        Slider {
            id: volumeSlider
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignLeft

            enabled: true
            to: 100.0
            value: 100.0
        }
    }
}
