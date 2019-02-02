import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import ToolBarPlugin 1.0
import Common 1.0

ToolBarItem {
    contentItem: Component {
        RowLayout {
            id: _rootTumbler

            Tumbler {
                id: _tumbler
                Layout.preferredHeight: visibleItemCount * 18

                property var lastActive

                visibleItemCount: 3
                wrap: false
                model: _resolutionModel

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

                    var activeElement = _resolutionModel.get(_tumbler.currentIndex);
                    if (activeElement) {
                        ViewSettings.resolutionWidth = activeElement.width;
                        ViewSettings.resolutionHeight = activeElement.height;
                    }
                }

                delegate: Rectangle {
                    id: _brick
                    radius: 3
                    border.color: "lightgrey"
                    opacity: 1.0 - Math.abs(Tumbler.displacement) / (Tumbler.tumbler.visibleItemCount / 2)
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
                    _tumbler.currentItemChanged();
                }
            }
            ResolutionModel {
                id: _resolutionModel
            }
        }
    }
}
