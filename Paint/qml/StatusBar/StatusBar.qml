import QtQuick 2.0
import NetworkPlugin 1.0

Flow {
    id: _rootStatusBar
    state: "disconnected"

    spacing: 10

    ConnectionStatusIcon {
        state: _rootStatusBar.state
    }
    Text {
        id: _connectionData
    }

    states: [
        State {
            name: "connected"
            PropertyChanges {
                target: _connectionData
                color: "green"
                text: "Online. Connected to " + ConnectionSettings.hostAddress + ":"
                                              + ConnectionSettings.port
            }
        },
        State {
            name: "disconnected"
            PropertyChanges {
                target: _connectionData
                color: "red"
                text: "Offline."
            }
        }
    ]
}
