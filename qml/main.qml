import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import Toolbar 1.0
import WorkAreaPlugin 1.0

ApplicationWindow {
    id: _rootWindow
    visible: true
    width: 860
    height: 640
    title: qsTr("Paint")

    header: Pane {
        Material.elevation: 5
        contentItem: ScalableToolBar {
            id: _toolBar
        }
    }

    WorkArea {
        id: _workArea

        width: _rootWindow.width
        height: _rootWindow.height - header.height

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
