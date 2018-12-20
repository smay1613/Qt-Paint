import QtQuick 2.0
import QtGraphicalEffects 1.0

Item {
    id: _rootIcon

    width: 15
    height: 15

    Image {
        id: _icon
        anchors.fill: _rootIcon

        readonly property string resourcePath: "qrc:/resources/connectionicons/"
    }

    ColorOverlay {
        id: _colorOverlay
        anchors.fill: _icon
        source: _icon
    }

    states: [
        State {
            name: "connecting"
            PropertyChanges {
                target: _icon
                source: _icon.resourcePath + "connecting.png"
            }
            PropertyChanges {
                target: _colorOverlay
                color: "yellow"
            }
        },
        State {
            name: "connected"
            PropertyChanges {
                target: _icon
                source: _icon.resourcePath + "connected.png"
            }
            PropertyChanges {
                target: _colorOverlay
                color: "green"
            }
        },
        State {
            name: "disconnected"
            PropertyChanges {
                target: _icon
                source: _icon.resourcePath + "disconnected.png"
            }
            PropertyChanges {
                target: _colorOverlay
                color: "red"
            }
        }
    ]
}
