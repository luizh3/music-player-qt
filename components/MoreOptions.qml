import QtQuick 2.12
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0

Rectangle {
    id: root
    color: "transparent"

    signal addToQueue

    property bool closePolicy

    onClosePolicyChanged: {
        if (closePolicy && !mouseAreaMoreOptions.containsMouse) {
            listMoreOptions.visible = false
        }
    }

    property list<Button> buttonList: [
        Button {
            text: "Adicionar à fila"
            onClicked: {
                root.addToQueue()
            }
        }
    ]

    Rectangle {
        id: listMoreOptions
        width: 200
        height: 200
        anchors.right: buttonMore.right
        anchors.top: buttonMore.bottom
        anchors.bottomMargin: 10
        color: "#1C1C1C"
        radius: 3
        visible: false

        MouseArea {
            id: mouseAreaMoreOptions
            anchors.fill: parent
            hoverEnabled: true
        }

        Column {
            width: parent.width
            height: parent.height

            Repeater {
                model: buttonList

                Button {
                    id: controlButton
                    text: modelData.text
                    width: parent.width - 10
                    height: 50
                    anchors.horizontalCenter: parent.horizontalCenter

                    contentItem: Text {
                        text: controlButton.text
                        font: controlButton.font
                        color: "#fff"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                    }

                    background: Rectangle {
                        color: mouseAreaButton.containsMouse ? "#3db0f7" : "#121212"
                        radius: 3
                    }

                    MouseArea {
                        id: mouseAreaButton
                        hoverEnabled: true
                        anchors.fill: parent

                        onClicked: {
                            modelData.clicked()
                        }
                    }
                }
            }
        }
    }

    Rectangle {
        id: buttonMore
        width: 30
        height: 30
        anchors.centerIn: parent
        color: "transparent"

        Image {
            id: image
            source: "/img/more.png"
            smooth: true
        }

        ColorOverlay {
            anchors.fill: image
            source: image
            color: "#fff" // make image like it lays under red glass
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true

            onClicked: {
                listMoreOptions.visible = !listMoreOptions.visible
            }
        }
    }
}
