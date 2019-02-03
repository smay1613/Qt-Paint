import QtQuick 2.0

Rectangle {
    id: _rootAnimator

    readonly property string resourcePath: "qrc:/resources/states/"
    property real time: 1500

    color: "transparent"

    onStateChanged: {
        if (_rootAnimator.state !== "none") {
            _disappearTimer.start();
        }
    }

    Image {
        id: _indicatorImage
        anchors.centerIn: _rootAnimator
        width: _rootAnimator.width
        height: width
        sourceSize.width: width
        sourceSize.height: width
    }

    Timer {
        id: _disappearTimer
        interval: _rootAnimator.time
        onTriggered: {
            _rootAnimator.state = "none";
        }
    }

    states: [
        State {
            name: "none"
            PropertyChanges {
                target: _rootAnimator
                color: "white"
                opacity: 0
            }
        },
        State {
            name: "success"
            PropertyChanges {
                target: _rootAnimator
                color: "lightgreen"
                opacity: 0.75
            }
            PropertyChanges {
                target: _indicatorImage
                source: _rootAnimator.resourcePath + "checked.svg"
                explicit: true
            }
        },
        State {
            name: "fail"
            PropertyChanges {
                target: _rootAnimator
                color: "#FFA07A"
                opacity: 0.75
            }
            PropertyChanges {
                target: _indicatorImage
                source: _rootAnimator.resourcePath + "failed.svg"
                explicit: true
            }
        }
    ]

    transitions: Transition {
        ParallelAnimation {
            NumberAnimation {
                target: _rootAnimator
                properties: "opacity"
                easing.type: Easing.Linear
                duration: _rootAnimator.time
            }
            PropertyAnimation {
                target: _rootAnimator
                properties: "color"
                easing.type: Easing.Linear
                duration: _rootAnimator.time
            }
        }
    }
}
