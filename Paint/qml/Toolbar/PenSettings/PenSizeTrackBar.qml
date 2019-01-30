import QtQuick 2.11
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import ToolBarPlugin 1.0
import Common 1.0

ColumnLayout {
    id: _rootPenSizeTrackBar
    objectName: "PenSizeTrackBarColumnLayout"

    Layout.topMargin: 5

    Slider {
        id: _sizeSlider
        Layout.preferredHeight: 20

        from: PaintSettings.penSizeMin
        to: PaintSettings.penSizeMax

        value: PaintSettings.penSizeDefault
        stepSize: 2

        onValueChanged: {
            PaintSettings.penSize = value;
        }
        BasicTooltip {
            text: "(" + _upShortCut.nativeText + " and " + _downShortCut.nativeText + ")"
        }
    }

    Text {
        text: "Pen size"
        Layout.alignment: Qt.AlignHCenter
    }

    Shortcut {
        id: _upShortCut
        sequence: StandardKey.MoveToPreviousPage
        onActivated: _sizeSlider.increase()
    }
    Shortcut {
        id: _downShortCut
        sequence: StandardKey.MoveToNextPage
        onActivated: _sizeSlider.decrease()
    }
}
