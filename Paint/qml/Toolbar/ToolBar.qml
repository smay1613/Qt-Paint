import QtQuick 2.0
import QtQuick.Layouts 1.3
import Toolbar.ColorPicker 1.0
import Toolbar.PenSettings 1.0
import Toolbar.ShapePicker 1.0
import Toolbar.ActionPicker 1.0
import Toolbar.Viewsettings 1.0

import NetworkPlugin 1.0

Flow {
    id: _rootToolbar
    objectName: "ToolBarFlow"

    readonly property bool isMasterMode: ConnectionSettings.connectionMode.valueOf() === Network.Master

    spacing: 5

    SaveButton {

    }
    ColorBar {
        objectName: "ColorBar"
        visible: isMasterMode
    }
    ShapePicker {
        objectName: "ShapePicker"
        visible: isMasterMode
    }
    ActionPicker {
        objectName: "ActionPicker"
        visible: isMasterMode
    }
    PenSizeTrackBar {
        objectName: "PenSizeBar"
        visible: isMasterMode
    }
    ZoomBox {
        objectName: "ZoomBox"
    }
    ResolutionTumbler {

    }
}
