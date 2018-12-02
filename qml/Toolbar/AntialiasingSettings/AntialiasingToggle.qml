import QtQuick 2.0
import QtQuick.Controls 2.2
import ToolBarPlugin 1.0

Switch {
    id: _rootToggle

    text: "Antialiasing"

    onCheckedChanged: {
        PaintSettings.antialiasing = checked;
    }

    ToolTip {
        id: toolTip
        text: "Antialiasing option - \n" +
               "makes image more smoothly, but highly loads CPU.\n" +
               "If you feel slow rendering, please remove this option."
        visible: _mouseArea.containsMouse
        delay: 1000
        timeout: 3000
    }

    MouseArea {
        id: _mouseArea
        anchors.fill: _rootToggle
        hoverEnabled: true
        propagateComposedEvents: true
        onPressed: mouse.accepted = false;
    }

    Component.onCompleted: {
        _rootToggle.checked = PaintSettings.antialiasing;
    }
}

