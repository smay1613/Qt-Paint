import QtQuick 2.0
import QtQuick.Controls 2.2
import Common 1.0
import ToolBarPlugin 1.0

SpinBox {
    id: _rootBox

    textFromValue: function (value) {
        return internal.scaleToPercents(value);
    }

    value: ViewSettings.scale * 100
    from: ViewSettings.minScale * 100
    to: ViewSettings.maxScale * 100
    stepSize: 15

    validator: IntValidator {}

    QtObject {
        id: internal
        function scaleToPercents(value) {
           return value + "%";
        }
    }

    onValueModified: {
        ViewSettings.scale = value / 100;
    }

    Connections {
        target: ViewSettings
        onScaleChanged: {
            _rootBox.value = ViewSettings.scale.toFixed(2) * 100;
        }
    }

    BasicTooltip {
        text: "Zoom in / zoom out.\nAlso you can use mouse wheel."
    }
}
