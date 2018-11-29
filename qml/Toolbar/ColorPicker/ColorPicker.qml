import QtQuick 2.0
import QtQuick.Layouts 1.3
import Common 1.0
import ToolBarPlugin 1.0

Picker {
    id: _rootColorPicker
    objectName: "ColorPickerGrid"

    model: _model

    delegateSource: "qrc:/qml/Toolbar/ColorPicker/ColorBox.qml"

    onActiveItemChanged: {
        PaintSettings.activeColor = _rootColorPicker.activeItem.color;
    }

    ColorsModel {
        id: _model
    }
}
