import QtQuick 2.11
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import ToolBarPlugin 1.0
import Common 1.0

RowLayout {
    id: _rootShapePicker
    objectName: "HistoryActionPickerRowLayout"

    property string resourcePath: "qrc:/resources/actionicons/"

    RoundButton {
        id: _undoButton
        background: ButtonBackground {}
        enabled: ActionManager.undoAvailable
        contentItem: ActionBox {
            source: resourcePath + "undo.svg"
        }
        onClicked: {
            ActionManager.undo();
        }
        BasicTooltip {
            text: "Undo action (" + _undoShortcut.nativeText + ")"
        }
        Shortcut {
            id: _undoShortcut
            sequence: StandardKey.Undo
            onActivated: {
                ActionManager.undo();
            }
        }
    }
    RoundButton {
        background: ButtonBackground {}
        enabled: ActionManager.redoAvailable
        contentItem: ActionBox {
            source: resourcePath + "redo.svg"
        }
        onClicked: {
            ActionManager.redo();
        }
        BasicTooltip {
            text: "Redo action (" + _redoShortcut.nativeText + ")"
        }
        Shortcut {
            id: _redoShortcut
            sequence: StandardKey.Redo
            onActivated: {
                ActionManager.redo();
            }
        }
    }
    RoundButton {
        background: ButtonBackground {}
        contentItem: ActionBox {
            source: resourcePath + "clear.svg"
        }
        onClicked: {
            ActionManager.clear();
        }
        BasicTooltip {
            text: "Clear workarea (" + _clearShortcut.nativeText + ")"
        }
        Shortcut {
            id: _clearShortcut
            sequence: StandardKey.Delete
            onActivated: {
                ActionManager.clear();
            }
        }
    }
}
