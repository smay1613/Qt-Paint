import QtQuick 2.11
import Common 1.0

Rectangle {
    width: 15
    height: 15
    radius: width / 6
    color: display // displayRole used

    function getShortcutSequence() {
        var shortCutSequence;
        if (Math.floor((index / columns)) == 1) { // second row!
            shortCutSequence = "Ctrl + Shift +";
        } else {
            shortCutSequence = "Shift + ";
        }

        shortCutSequence += Math.floor(index % columns) + 1;
        return shortCutSequence;
    }

    BasicTooltip {
        id: tooltip
        text: display + " (" + getShortcutSequence() + ")"
    }

    Shortcut {
        sequence: qsTr(getShortcutSequence().replace(/ /g, ''))
        onActivated: requestActivate(index)
    }
}
