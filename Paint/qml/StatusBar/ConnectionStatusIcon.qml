import QtQuick 2.0
import QtGraphicalEffects 1.0
import Icons 1.0

Item {
    id: _rootIcon

    width: 15
    height: 15

    Image {
        id: _icon
        anchors.fill: _rootIcon
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
                source: Icons.connectionIcons.connecting
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
                source: Icons.connectionIcons.connected
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
                source: Icons.connectionIcons.disconnected
            }
            PropertyChanges {
                target: _colorOverlay
                color: "red"
            }
        }
    ]
}
