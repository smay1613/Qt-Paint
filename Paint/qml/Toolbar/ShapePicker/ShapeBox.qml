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
    signal requestActivate

    Image {
        id: _image
        anchors.centerIn: _rootButton
        width: 30
        height: 30
        property var type: model.type
        sourceSize.width: width
        sourceSize.height: height
        source: model.display
    }

    background: Rectangle {color: "transparent"}

    Rectangle {
        anchors.centerIn: _rootButton
        width: _rootButton.width + 8
        height: _rootButton.height + 8
        color: "transparent"
        border.color: "lightgrey"
        radius: width / 2
    }

    BasicTooltip {
        text: _image.type.toString() + " (Ctrl+" + (index + 1) + ")"
    }
    Shortcut {
        sequence: "Ctrl+" + (index + 1)
        onActivated: requestActivate(index)
    }
}
