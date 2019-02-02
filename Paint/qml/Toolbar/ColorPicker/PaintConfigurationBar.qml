import QtQuick 2.0
import QtQuick.Layouts 1.3
import ToolBarPlugin 1.0
import Common 1.0

ToolBarItem {
    contentItem: Component {
        RowLayout {
            objectName: "PaintConfigurationBarRowLayout"

            Layout.leftMargin: 5
            spacing: 15

            ColumnLayout {
                id: _activeColorBox

                Layout.alignment: Qt.AlignVCenter
                Layout.topMargin: 5

                Rectangle {
                    Layout.preferredWidth: 25
                    Layout.preferredHeight: 25

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
                id: _colorPicker

                Layout.alignment: Qt.AlignVCenter
            }
        }
    }
}
