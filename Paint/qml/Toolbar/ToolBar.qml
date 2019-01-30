import QtQuick 2.0
import QtQuick.Layouts 1.3
import Toolbar.ColorPicker 1.0
import Toolbar.PenSettings 1.0
import Toolbar.ShapePicker 1.0
import Toolbar.ActionPicker 1.0
import Toolbar.Viewsettings 1.0

Flow {
    id: _rootToolbar
    objectName: "ToolBarFlow"

    spacing: 15

    ColorBar {
        objectName: "ColorBar"
    }
    ShapePicker {
        objectName: "ShapePicker"
    }
    ActionPicker {
        objectName: "ActionPicker"
    }
    PenSizeTrackBar {
        objectName: "PenSizeBar"
    }
    ZoomBox {
        objectName: "ZoomBox"
    }
    ResolutionTumbler {

    }
}
