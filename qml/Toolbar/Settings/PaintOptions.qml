pragma Singleton
import QtQuick 2.0

// TODO: Move this singleton to C++

QtObject {
    property var activeColor
    property var activeShape
    property int penSize: penSizeDefault

    readonly property int penSizeDefault: 14
    readonly property int penSizeMin: 1
    readonly property int penSizeMax: 72

    onActiveColorChanged: {
        console.log("Active color set " + activeColor)
    }
    onPenSizeChanged: {
        console.log("Pen size set " + penSize)
    }
}
