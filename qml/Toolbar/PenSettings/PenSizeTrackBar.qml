import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import Toolbar.Settings 1.0 as Settings

ColumnLayout {
    id: _rootPenSizeTrackBar
    objectName: "PenSizeTrackBarItem"

    Layout.topMargin: 5

    Slider {
        Layout.preferredHeight: 30

        from: Settings.PaintOptions.penSizeMin
        to: Settings.PaintOptions.penSizeMax

        value: Settings.PaintOptions.penSizeDefault
        stepSize: 2

        onValueChanged: {
            Settings.PaintOptions.penSize = value;
        }
    }

    Text {
        text: "Pen size"
        Layout.alignment: Qt.AlignHCenter
    }
}
