import QtQuick 2.0
import QtQuick.Layouts 1.3
import ToolBarPlugin 1.0

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

            color: PaintSettings.activeColor
        }
        Text {
            text: "Pen color"
        }
    }

    ColorPicker {
        model: _model

        Layout.alignment: Qt.AlignVCenter

        onActiveColorChanged: {
            PaintSettings.activeColor = activeColor;
        }

        ColorsModel {
            id: _model
        }
    }
}
