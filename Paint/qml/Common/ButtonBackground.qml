import QtQuick 2.0

Rectangle {
    anchors.centerIn: parent
    width: parent.width * 0.7
    height: parent.height * 0.7
    Gradient {
        id: _gradient
        GradientStop { position: 0.5; color: "#a145a1" }
        GradientStop { position: 1; color: "white" }
    }
    gradient: enabled ? null : _gradient
    color: "#8BC34A"
    opacity: 0.2
    border.width: 1
    radius: parent.radius
}
