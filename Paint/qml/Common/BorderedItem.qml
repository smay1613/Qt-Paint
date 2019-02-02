import QtQuick 2.0

Item {
    id: _root

    width: _contentLoader.item.width * 1.15
    height: _contentLoader.item.height * 1.15

    property var contentItem

    Loader {
        id: _contentLoader
        anchors.centerIn: _root
        sourceComponent: _root.contentItem
    }

    Rectangle {
        id: _border
        width: _root.width
        height: _root.height
        anchors.centerIn: _root
        z: -1
        radius: 8
        color: "transparent"
        border.color: "lightgrey"
    }
}
