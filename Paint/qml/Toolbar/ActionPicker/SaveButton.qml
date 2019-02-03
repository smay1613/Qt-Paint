import QtQuick 2.11
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4
import ToolBarPlugin 1.0
import Common 1.0

ToolBarItem {
    id: _rootSaveButton

    contentItem: Component {
        Item {
            width: _saveColumn.implicitWidth
            height: _saveColumn.implicitHeight
            ColumnLayout {
                id: _saveColumn

                property string resourcePath: "qrc:/resources/actionicons/"

                Layout.alignment: Qt.AlignVCenter

                Button {
                    id: _saveButton
                    Layout.preferredWidth: 30
                    Layout.preferredHeight: 30

                    Layout.alignment: Qt.AlignHCenter

                    Image {
                        id: _saveImage
                        width: 25
                        height: 25
                        anchors.centerIn: _saveButton
                        source: _saveColumn.resourcePath + "save.svg"

                        sourceSize.width: width
                        sourceSize.height: height
                    }
                    background: Rectangle {color: "transparent"}
                    onClicked: {
                        _saveDialog.open();
                    }
                }

                Text {
                    text: "Save"
                }
            }

            Rectangle {
                anchors.fill: _saveColumn
                z: -1
                color: _saveButton.pressed ? "lightgrey" : "transparent"
                radius: 5
            }
        }
    }

    ImageSaveDialog {
        id: _saveDialog
        onAccepted: {
            ActionManager.save(_saveDialog.fileUrl);
        }
    }

    BasicTooltip {
        text: "Save image to selected location (" + _saveShortcut.nativeText + ")"
    }
    Shortcut {
        id: _saveShortcut
        sequence: StandardKey.Save
        onActivated: {
            _saveDialog.open();
        }
    }

}
