import QtQuick 2.9
import QtQuick.Controls 2.2
import Common 1.0
import ToolBarPlugin 1.0
import WorkAreaPlugin 1.0
import NetworkPlugin 1.0

Flickable {
    id: _rootArea

    contentWidth: _workArea.width * _scaler.currentScale
    contentHeight: _workArea.height * _scaler.currentScale

    ScrollBar.horizontal: ScrollBar {
    }
    ScrollBar.vertical: ScrollBar {
    }
    interactive: false

    WorkArea {
        id: _workArea
        width: ViewSettings.resolutionWidth
        height: ViewSettings.resolutionHeight

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
        width: Math.max(_rootArea.contentWidth, _rootArea.width)
        height: Math.max(_rootArea.contentHeight, _rootArea.height)
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
        width: _rootArea.contentWidth
        height: _rootArea.contentHeight
        z: -1
        color: "lightgrey"
        opacity: 0.5
    }
}
