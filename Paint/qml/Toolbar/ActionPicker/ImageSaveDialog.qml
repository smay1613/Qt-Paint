import QtQuick 2.9
import QtQuick.Dialogs 1.2

FileDialog {
    id: _fd
    selectExisting: false
    selectMultiple: false
    folder: shortcuts.pictures
    nameFilters: [ "Image files (*.jpg *.png)", "All files (*)" ]
}
