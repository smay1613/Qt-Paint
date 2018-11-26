import QtQuick 2.9
import QtQuick.Window 2.2
import "."
import Toolbar 1.0
import WorkArea 1.0

Window {
    id: _rootWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Paint")

    ToolBar {
        id: _toolBar
        anchors.top: _rootWindow.top
    }

    WorkArea {
        id: _workArea

        width: _rootWindow.width
        height: _rootWindow.height - _toolBar.height

        anchors.top: _toolBar.bottom
        anchors.topMargin: 10

        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton
            hoverEnabled: true

            onReleased: {
                _workArea.mouseReleased(mouseX, mouseY);
            }

            onPressed: {
                _workArea.mouseClicked(mouseX, mouseY);
            }

            onPositionChanged: {
                _workArea.mousePositionChanged(mouseX, mouseY, pressed);
            }
        }
    }
}
