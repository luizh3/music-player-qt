import QtQuick 2.0

import QtQuick.Layouts 1.0
import QtMultimedia 5.0
import QtQuick.Controls 2.0

Item {
    id: root

    property MediaPlayer mediaPlayer

    ComboBox {
        width: root.width
        currentIndex: 0
        displayText: "Velocidade"
        model: ["1.25", "1.10", "1.0", "0.90", "0.75", "0.50"]
        background: Rectangle {
            color: "transparent"
        }

        onCurrentIndexChanged: {
            mediaPlayer.playbackRate = parseFloat(textAt(currentIndex))
        }
    }
}
