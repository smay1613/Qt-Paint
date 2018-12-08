import QtQuick 2.0

MouseArea {
    property var scaleTransformObject

    property real minScale: 0
    property real maxScale: 10

    property real currentScale: 1

    function performScale(scale) {
        if (scale < maxScale && scale > minScale) {
            scaleTransformObject.xScale = scale;
            scaleTransformObject.yScale = scale;
            currentScale = scale;
        }
    }

    propagateComposedEvents: true
    hoverEnabled: true

    onClicked: mouse.accepted = false
    onPressed: mouse.accepted = false
    onReleased: mouse.accepted = false
    onWheel: {
        var scale = currentScale + ((wheel.angleDelta.y < 0) ? -0.1 :
                                                               0.1); // zoom in or out

        performScale(scale);
    }
}
