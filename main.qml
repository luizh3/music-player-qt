import QtQuick 2.12
import QtQml 2.0
import QtQuick.Controls 2.1
import QtGraphicalEffects 1.0
import QtQuick.Controls.Material 2.12

import br.com.listsongscontroller 1.0

import "components"
import "components/music"
import "components/Effect"
import "components/Animate"
import "components/album"

ApplicationWindow {
    id: root
    width: 1300
    height: 800
    visible: true
    title: qsTr("Hello World")
    flags: Qt.FramelessWindowHint | Qt.WindowMinimizeButtonHint | Qt.Window
    visibility: "Windowed"

    Material.theme: Material.Dark
    Material.accent: Material.Blue
    Material.elevation: 0

    property int previousX

    MouseArea {
        anchors.fill: parent
        onPressed: {
            pos = Qt.point(mouse.x, mouse.y)
            previousX = mouseX
        }

        onPositionChanged: {
            var diff = Qt.point(mouse.x - pos.x, mouse.y - pos.y)
            ApplicationWindow.window.x += diff.x
            ApplicationWindow.window.y += diff.y
        }
        property point pos
    }

    // TODO isso e temporario, alterar para listar albums/musicas na mainscreen
    property var screenVisible: listSongsController.albums.length > 0 ? listAlbums : listLastMusics

    property bool hasWindowed: true

    function changeScreenVisible(newScreen) {
        screenVisible.visible = false
        screenVisible = newScreen
        screenVisible.visible = true
    }

    function changeVisibleMode() {
        hasWindowed = !hasWindowed
        root.visibility = hasWindowed ? "Windowed" : "FullScreen"
    }

    background: Rectangle {
        border.width: 0
        border.color: "#fff"
        color: "#121212"
    }

    ListSongsController {
        id: listSongsController
    }

    Row {
        width: root.width
        height: root.height

        SideBar {
            id: sideBar
            height: parent.height
            maximumWidth: parent.width / 1.3
            z: 1

            onUrlMusic: function (url) {
                listSongsController.addSong(url)
            }

            onQueueMusicsPressed: {
                changeScreenVisible(musicQueue)
            }

            onInicioPressed: {
                // TODO isso e temporario
                var component = listSongsController.albums.length > 0 ? listAlbums : listLastMusics
                changeScreenVisible(component)
            }

            onEffectsPressed: {
                effectControl.visible = !effectControl.visible
            }

            onAnimatedSpacePressed: {
                changeScreenVisible(animateScreen)
            }
        }

        BarMusicManager {
            id: barMusicManager
            width: parent.width - sideBar.minimumWidth
            visible: true
        }

        Rectangle {
            width: barMusicManager.width
            height: 1
            color: "#1C1C1C"
            anchors.top: barMusicManager.top
            anchors.right: barMusicManager.right
        }

        Animate {
            id: animateScreen
            visible: false
            width: parent.width - sideBar.minimumWidth
            height: root.height - (header.height)
            anchors.top: header.bottom
            anchors.bottom: barMusicManager.top
            anchors.left: sideBar.right
        }

        EffectControl {
            id: effectControl
            anchors.left: sideBar.right
            height: parent.height
            visible: false
            z: 13
        }

        RectangularGlow {
            anchors.fill: sideBar
            glowRadius: 20
            cornerRadius: 25
            spread: 0.0
            color: "#000"
            opacity: 0.7
            visible: sideBar.visible
        }

        Column {
            id: columnMain
            width: parent.width - sideBar.minimumWidth
            height: parent.height
            anchors.right: parent.right
            spacing: 20

            // TODO to remove header from here
            Header {
                id: header
                width: parent.width
            }

            MusicQueue {
                id: musicQueue
                visible: false
                width: parent.width
                height: parent.height - (header.height + barMusicManager.height + (parent.spacing))
                musicController: barMusicManager.musicController
            }

            AlbumList {
                id: albumList
                visible: false
                width: parent.width
                height: parent.height - (header.height + barMusicManager.height + (parent.spacing))
                musicController: barMusicManager.musicController
            }

            ListView {
                id: listLastMusics
                visible: listSongsController.songs.length > 0
                width: parent.width - (parent.spacing * 2)
                height: 350
                anchors.horizontalCenter: parent.horizontalCenter
                layoutDirection: Qt.LeftToRight
                orientation: ListView.Horizontal
                spacing: 20

                Component {
                    id: delegate

                    CardMusic {
                        id: cardMusic
                        source: modelData.sourceImage
                        nameMusic: modelData.nameMusic
                        artist: modelData.artist
                        album: modelData.album
                        release: modelData.release
                        genre: modelData.genre
                        sourceMusic: modelData.sourceMusic
                        onAddToQueue: {
                            barMusicManager.visible = true
                            barMusicManager.addMusicQueue(modelData)
                        }
                    }
                }

                model: listSongsController.songs
                delegate: delegate
            }

            ListView {
                id: listAlbums
                visible: listSongsController.albums.length > 0
                width: parent.width - (parent.spacing * 2)
                height: 350
                anchors.horizontalCenter: parent.horizontalCenter
                layoutDirection: Qt.LeftToRight
                orientation: ListView.Horizontal
                spacing: 20

                Component {
                    id: delegateListAlbums

                    CardAlbum {
                        sourceImage: modelData.urlImage
                        nameAlbum: modelData.name
                        artist: modelData.artist
                        release: modelData.releaseDate
                        genre: modelData.genre
                        onClicked: {
                            albumList.albumModel = modelData
                            changeScreenVisible(albumList)
                        }
                    }
                }

                model: listSongsController.albums
                delegate: delegateListAlbums
            }
        }
    }
}
