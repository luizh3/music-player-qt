import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtMultimedia 5.0

Item {
    id: root

    property MediaPlayer mediaPlayer

    function toMinute(time) {
        var m = Math.floor(time / 60000)
        var ms = (time / 1000 - m * 60).toFixed(1)
        return m + ":" + ms.padStart(4, 0)
    }

    RowLayout {
        anchors.fill: parent

        Text {
            id: timeActual
            Layout.minimumWidth: 50
            Layout.minimumHeight: 18
            horizontalAlignment: Text.AlignRight
            color: "#fff"
            text: {
                return toMinute(mediaPlayer.position)
            }
        }

        Slider {
            id: mediaSlider
            Layout.fillWidth: true
            enabled: mediaPlayer.seekable
            to: 1.0
            value: mediaPlayer.position / mediaPlayer.duration
            onMoved: mediaPlayer.seek(value * mediaPlayer.duration)
        }

        Text {
            id: allDuration
            horizontalAlignment: Text.AlignRight
            color: "#fff"
            text: {
                return toMinute(mediaPlayer.duration)
            }
        }
    }
}
