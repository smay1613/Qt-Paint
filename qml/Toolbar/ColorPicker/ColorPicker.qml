import QtQuick 2.0
import QtQuick.Layouts 1.3

Grid {
    id: _rootColorPicker
    objectName: "ColorPickerGrid"

    property var model
    property var activeColor

    columns: model ? model.rowCount() / 2
                   : 1
    rows: 2

    columnSpacing: 1
    rowSpacing: 3

    Repeater {
        id: _colorsPalette
        model: _rootColorPicker.model

        property int activeColorIndex

        // we should configure it on palette level,
        // because each color box should know nothing about another one
        function setActive(index) {
            if (activeColorIndex >= 0) {
                itemAt(activeColorIndex).active = false;
            }

            if (index >= 0) {
                var activeItem = itemAt(index);
                activeItem.active = true;
                activeColorIndex = index;
                _rootColorPicker.activeColor = activeItem.boxColor;
            }
        }

        delegate: Rectangle {
            id: _colorBoxWrapper

            property bool active: false
            property color boxColor: _colorBox.color

            width: 20 // same as in Paint
            height: 20

            radius: width / 6

            border.color: active ? "black" : "lightgrey"
            border.width: 1

            Rectangle {
                id: _colorBox
                anchors.fill: _colorBoxWrapper
                anchors.margins: 2

                radius: width / 6

                color: display // displayRole as color

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        _colorsPalette.setActive(index);
                    }
                }
            }
        }

        Component.onCompleted: {
            setActive(0); // first colorbox will be highlighted at startup
        }
    }
}
