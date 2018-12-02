import QtQuick 2.0
import QtQuick.Controls 2.2

Item {
    id: _rootTooltip

    property var target: parent
    property string text

    anchors.fill: target

    ToolTip {
        id: _toolTip
        text: _rootTooltip.text
        visible: _mouseArea.containsMouse
        delay: 1000
        timeout: 5000
    }

    MouseArea {
        id: _mouseArea
        anchors.fill: _rootTooltip
        hoverEnabled: true
        propagateComposedEvents: true
        onPressed: mouse.accepted = false;
    }
}
