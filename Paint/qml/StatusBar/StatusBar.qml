import QtQuick 2.9
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import NetworkPlugin 1.0

Flow {
    id: _rootStatusBar
    state: ConnectionSettings.connectionState

    spacing: 10

    ConnectionStatusIcon {
        state: _rootStatusBar.state
    }
    Text {
        id: _connectionData
    }

    Text {
        id: _reconnectionData
        property int reconnectionTime: ConnectionSettings.reconnectionTime
        property int currentTime: 0
        text: "Reconnection attempt in: " + (currentTime / 1000).toFixed(1) + "s"
        color: "red"
        visible: _rootStatusBar.state === "disconnected"
    }

    BusyIndicator {
        running: true
        height: _reconnectionData.height
        width: height
        visible: _rootStatusBar.state === "disconnected"
    }

    PropertyAnimation {
        id: _anim
        target: _reconnectionData
        property: "currentTime"
        duration: _reconnectionData.reconnectionTime
        from: _reconnectionData.reconnectionTime
        to: 0
    }

    Connections {
        target: ConnectionSettings
        onReconnectionStarted: {
            _anim.stop();
            _anim.start();
        }
    }

    states: [
        State {
            name: "connecting"
            PropertyChanges {
                target: _connectionData
                color: "darkyellow"
                text: "Connecting to host" + ConnectionSettings.hostAddress + ":"
                      + ConnectionSettings.port
            }
        },
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
