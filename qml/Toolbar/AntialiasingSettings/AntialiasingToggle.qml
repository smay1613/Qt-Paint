import QtQuick 2.0
import Common 1.0
import QtQuick.Controls 2.2
import ToolBarPlugin 1.0

Switch {
    id: _rootToggle

    text: "Antialiasing"

    onCheckedChanged: {
        PaintSettings.antialiasing = checked;
    }

    BasicTooltip {
        id: toolTip
        target: _rootToggle
        text: "Antialiasing option - \n" +
               "makes image more smoothly, but highly loads CPU.\n" +
               "If you feel slow rendering, please remove this option."
    }

    Component.onCompleted: {
        _rootToggle.checked = PaintSettings.antialiasing;
    }
}

