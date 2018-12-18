import QtQuick 2.9
import QtQuick.Controls 2.4
import Common 1.0

RoundButton {
    id: _rootButton

    property alias shapeType: _image.type

    contentItem: Image {
        id: _image
        property var type: model.type
        sourceSize.width: 35
        sourceSize.height: 35
        source: model.display
    }
    BasicTooltip {
        text: _image.type.toString() + " (Ctrl+" + (index + 1) + ")"
    }
    Shortcut {
        sequence: "Ctrl+" + (index + 1)
        onActivated: requestActivate(index)
    }
}