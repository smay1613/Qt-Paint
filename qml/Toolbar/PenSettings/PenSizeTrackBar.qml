import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import ToolBarPlugin 1.0

ColumnLayout {
    id: _rootPenSizeTrackBar
    objectName: "PenSizeTrackBarColumnLayout"

    Layout.topMargin: 5

    Slider {
        Layout.preferredHeight: 30

        from: PaintSettings.penSizeMin
        to: PaintSettings.penSizeMax

        value: PaintSettings.penSizeDefault
        stepSize: 2

        onValueChanged: {
            PaintSettings.penSize = value;
        }
    }

    Text {
        text: "Pen size"
        Layout.alignment: Qt.AlignHCenter
    }
}
