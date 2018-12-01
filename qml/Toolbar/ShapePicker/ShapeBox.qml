import QtQuick 2.9
import QtQuick.Controls 2.4

RoundButton {
    id: _rootButton

    property var shapeType: _image.type

    contentItem: Image {
        id: _image
        property var type: model.type
        sourceSize.width: 35
        sourceSize.height: 35
        source: model.display
    }
}
