import QtQuick 2.9
import QtQuick.Controls 2.2
import Common 1.0
import ToolBarPlugin 1.0
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

        scaleTransformObject: _scaleTransform

        minScale: ViewSettings.minScale
        maxScale: ViewSettings.maxScale

        onCurrentScaleChanged: {
            ViewSettings.scale = currentScale;
        }

        Connections {
            target: ViewSettings
            onScaleChanged: {
                _scaler.performScale(scale);
            }
        }
    }

    Rectangle {
        id: _background
        anchors.fill: _rootArea
        z: -1
        color: "lightgrey"
        opacity: 0.5
    }
}
