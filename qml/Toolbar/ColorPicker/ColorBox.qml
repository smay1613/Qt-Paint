import QtQuick 2.0
import Common 1.0

Rectangle {
    width: 20
    height: 20
    radius: width / 6
    color: display // displayRole used
    BasicTooltip {
        text: display
    }
}
