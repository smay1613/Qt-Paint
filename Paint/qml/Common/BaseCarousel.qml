import QtQuick 2.0
import QtGraphicalEffects 1.0

PathView {
    id: _rootCarousel

    property string highlightColor: "lightgreen"
    property string mainColor: "white"

    preferredHighlightBegin: 0.5
    preferredHighlightEnd: 0.5
    highlightRangeMode: PathView.StrictlyEnforceRange

    clip: true
    highlightMoveDuration: 100
    maximumFlickVelocity: 1000

    highlight: Component {
        Rectangle {
            radius: width / 2
            visible: PathView.onPath
            anchors.centerIn: _rootCarousel.currentItem
            width: _rootCarousel.currentItem.width + 10
            height: _rootCarousel.currentItem.height + 10
            color: mainColor
        }
    }

    snapMode: PathView.SnapToItem

    Glow {
        anchors.fill: highlightItem
        source: highlightItem
        color: highlightColor
        transparentBorder: true
        radius: 5
        spread: 0.7
    }

    Keys.onLeftPressed: decrementCurrentIndex()
    Keys.onRightPressed: incrementCurrentIndex()
}
