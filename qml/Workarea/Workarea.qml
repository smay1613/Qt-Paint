import QtQuick 2.9
import QtQuick.Controls 2.2
import Common 1.0
import WorkAreaPlugin 1.0

Item {
    id: _rootArea

    WorkArea {
        id: _workArea
        width: 1920
        height: 1080

        transform: Scale {
            id: _scaleTransform
        }

        BorderShadow {
            anchors.fill: _workArea
            z: -1
        }
    }

    Scaler {
        id: _scaler
        anchors.fill: _rootArea

        source: _workArea
        scaleTransformObject: _scaleTransform

        scaleFactor: 0.9
        minScale: 0.3
        maxScale: 5
    }
}
