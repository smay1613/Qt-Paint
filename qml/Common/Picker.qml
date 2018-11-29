import QtQuick 2.0
import QtQuick.Layouts 1.3

Grid {
    id: _rootPicker
    objectName: "PickerGrid"

    property var model
    property var activeItem

    property string delegateSource

    columns: model ? model.rowCount() / 2
                   : 1
    rows: 2

    columnSpacing: 1
    rowSpacing: 3

    Repeater {
        id: _dataRepeater
        model: _rootPicker.model

        property int activeItemIndex

        // we should configure it on data repeater level,
        // because each item box should know nothing about another one
        function setActive(index) {
            if (activeItemIndex >= 0) {
                itemAt(activeItemIndex).active = false;
            }

            if (index >= 0) {
                var newActiveItem = itemAt(index);
                newActiveItem.active = true;
                activeItemIndex = index;
                _rootPicker.activeItem = newActiveItem.itemBox;
            }
        }

        delegate: Rectangle {
            id: _itemBoxWrapper

            property bool active: false
            property var itemBox: _itemBoxLoader.item

            width: _itemBoxLoader.item.width + 4 // WARNING: Parent depends on dynamically loaded child!
            height: _itemBoxLoader.item.height + 4

            radius: width / 6

            border.color: active ? "black" : "lightgrey"
            border.width: 1

            Loader {
                id: _itemBoxLoader

                anchors.centerIn: _itemBoxWrapper

                source: _rootPicker.delegateSource
            }

            MouseArea {
                anchors.fill: _itemBoxWrapper
                onClicked: {
                    _dataRepeater.setActive(index);
                }
            }
        }

        Component.onCompleted: {
            setActive(0); // first box will be highlighted after completing
        }
    }
}
