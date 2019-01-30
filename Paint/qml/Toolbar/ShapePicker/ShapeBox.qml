import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0
import Common 1.0

RoundButton {
    id: _rootButton

    width: 40
    height: 40

    property alias shapeType: _image.type

    contentItem: Image {
        id: _image
        property var type: model.type
        sourceSize.width: 25
        sourceSize.height: 25
        source: model.display
    }

    background: Rectangle {color: "transparent"}

    BasicTooltip {
        text: _image.type.toString() + " (Ctrl+" + (index + 1) + ")"
    }
    Shortcut {
        sequence: "Ctrl+" + (index + 1)
        onActivated: requestActivate(index)
    }
}
