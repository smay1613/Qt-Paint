import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import ToolBarPlugin 1.0
import Common 1.0

RowLayout {
    id: _rootTumbler

    Tumbler {
        id: _tumbler
        Layout.preferredHeight: visibleItemCount * 20

        property var lastActive

        visibleItemCount: 3
        wrap: false
        model: _resolutionModel

        // CAUTION: VERY DIRTY HACK!
        // Too frequently tumbler update will cause workarea to resize frequently
        // But after some time, workarea's combination FramebufferObject + antialiasing
        // will cause the whole system freeze (maybe some qt bug)
        // Also, Qt documentation says that Framebufferobject shouldn't be resized too often
        // So this post timer prevents tumbler to be "live" - thats,
        // resolution will be changed only after 0.5 s after user will release the mouse.
        Timer {
            id: _postTimer
            interval: 500
            running: false
            onTriggered: {
                var activeElement = _resolutionModel.get(_tumbler.currentIndex);
                if (activeElement) {
                    ViewSettings.resolutionWidth = activeElement.width;
                    ViewSettings.resolutionHeight = activeElement.height;
                }
            }
        }

        BasicTooltip {
            text: "Work area size.\n" +
                  "Note, bigger size can slow down the painting."
        }

        onCurrentItemChanged: {
            if (lastActive) {
                lastActive.state = "Disabled";
            }
            currentItem.state = "Active";
            lastActive = currentItem;
            _postTimer.restart();
        }

        delegate: Rectangle {
            id: _brick
            radius: 5
            border.color: "lightgrey"
            Text {
                anchors.right: _brick.right
                font.pointSize: 10
                text: name
            }
            states: [
                State {
                    name: "Active"
                    PropertyChanges {
                        target: _brick
                        color: "lightgrey"
                    }
                },
                State {
                    name: "Disabled"
                    PropertyChanges {
                        target: _brick
                        color: "white"
                    }
                }

            ]
        }

        Component.onCompleted: {
            _tumbler.currentIndex = 2;
        }
    }
    ResolutionModel {
        id: _resolutionModel
    }
}
