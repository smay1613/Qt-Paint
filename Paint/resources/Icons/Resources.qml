pragma Singleton
import QtQml 2.2

QtObject {
    property var connectionIcons: QtObject {
        readonly property string resourcePath: "qrc:/images/resources/Icons/connectionicons/"
        readonly property string connected: resourcePath + "connected.png"
        readonly property string connecting: resourcePath + "connecting.png"
        readonly property string disconnected: resourcePath + "disconnected.png"
    }

    property var actionIcons: QtObject {
        readonly property string resourcePath: "qrc:/images/resources/Icons/actionicons/"
        readonly property string clear: resourcePath + "clear.svg"
        readonly property string undo: resourcePath + "undo.svg"
        readonly property string redo: resourcePath + "redo.svg"
        readonly property string save: resourcePath + "save.svg"
    }

    property var stateIcons: QtObject {
        readonly property string resourcePath: "qrc:/images/resources/Icons/states/"
        readonly property string checked: resourcePath + "checked.svg"
        readonly property string failed: resourcePath + "failed.svg"
    }
}
