pragma Singleton
import QtQuick 2.0

QtObject {
    property var activeColor
    property var activeShape
    property var penSize

    onActiveColorChanged: {
        console.log("Active color set " + activeColor)
    }
}
