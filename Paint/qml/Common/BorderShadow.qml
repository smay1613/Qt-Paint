import QtQuick 2.0
import QtGraphicalEffects 1.0

Item {
    id: _root

    Rectangle {
        id: _dummyObject
        anchors.fill: _root
        visible: false
    }
    DropShadow {
        anchors.fill: _root
        transparentBorder: true
        radius: 15
        source: _dummyObject
    }
}
