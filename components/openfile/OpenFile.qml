import QtQuick 2.0
import QtQuick.Dialogs 1.0

FileDialog {
    id: root
    visible: root.visible
    title: "Please choose a file"
    folder: shortcuts.home
    nameFilters: "*.mp3"

    signal url(var textUrl)
    signal canceld

    onAccepted: {
        console.log(root.fileUrl)
        root.url(root.fileUrl)
    }
    onRejected: {
        root.canceld()
    }
}
