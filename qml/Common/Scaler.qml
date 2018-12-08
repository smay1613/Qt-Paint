import QtQuick 2.0

MouseArea {
    property var source
    property var scaleTransformObject

    property real scaleFactor: 0.5
    property real minScale: 0
    property real maxScale: 10

    property real currentScale: 1

    propagateComposedEvents: true
    hoverEnabled: true

    onClicked: mouse.accepted = false
    onPressed: mouse.accepted = false
    onReleased: mouse.accepted = false
    onWheel: {
        var origin = mapToItem(source, wheel.x, wheel.y);
        var scale = (wheel.angleDelta.y < 0) ? scaleFactor :
                                               1 / scaleFactor; // zoom in or out

        var newScale = _scaleTransform.yScale * scale;

        if (newScale < maxScale && newScale > minScale) {
            scaleTransformObject.xScale = newScale;
            scaleTransformObject.yScale = newScale;
            currentScale = newScale;
        }
    }
}
