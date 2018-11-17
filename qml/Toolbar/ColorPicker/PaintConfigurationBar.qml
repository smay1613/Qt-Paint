import QtQuick 2.0
import QtQuick.Layouts 1.3
//import "."
import Toolbar.Settings 1.0 as Settings

RowLayout {
    id: _rootColorBar
    objectName: "PaintConfigurationBarRowLayout"

    Layout.leftMargin: 5
    spacing: 15 // just some magic!

    ColumnLayout {
        id: _activeColorBox

        Layout.alignment: Qt.AlignVCenter
        Layout.topMargin: 5

        Rectangle {
            Layout.preferredWidth: 30  // magic here too
            Layout.preferredHeight: 30

            Layout.alignment: Qt.AlignHCenter

            border.color: "lightGrey"
            border.width: 1
            radius: width / 6

            color: Settings.PaintOptions.activeColor
        }
        Text {
            text: "Pen color"
        }
    }

    ColorPicker {
        model: colorsModel

        Layout.alignment: Qt.AlignVCenter

        onActiveColorChanged: {
            Settings.PaintOptions.activeColor = activeColor;
        }
    }
}
