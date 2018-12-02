import QtQuick 2.0
import QtQuick.Layouts 1.3
import Toolbar.ColorPicker 1.0
import Toolbar.PenSettings 1.0
import Toolbar.ShapePicker 1.0
import Toolbar.ActionPicker 1.0
import Toolbar.AntialiasingSettings 1.0

GridLayout {
    id: _rootToolbar
    objectName: "ToolBarRowLayout"

    rowSpacing: 15
    columnSpacing: 15

    ColorBar {
        id: _colorBar
    }
    ShapePicker {
        id: _shapePicker
    }
    ActionPicker {
        id: _actionPicker
    }
    PenSizeTrackBar {
        width: 150
    }
    AntialiasingToggle {
        id: _antialiasingToggle
    }
}
