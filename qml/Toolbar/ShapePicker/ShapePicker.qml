import QtQuick 2.0
import Common 1.0
import ToolBarPlugin 1.0

Picker {
    id: _rootShapePicker
    objectName: "ColorPickerGrid"

    rows: 1
    columns: _model.rowCount()

    model: _model
    delegateSource: Qt.resolvedUrl("ShapeBox.qml")

    ShapesModel {
        id: _model
    }

    onActiveItemChanged: {
        PaintSettings.activeShape = _rootShapePicker.activeItem.shapeType;
    }
}
