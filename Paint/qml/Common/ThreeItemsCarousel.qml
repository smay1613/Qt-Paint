import QtQuick 2.0

BaseCarousel {
    id: _rootCarousel
    pathItemCount: 3

    path: Path {
        startX: 0
        startY: _rootCarousel.height / 2

        PathAttribute { name: "iconScale"; value: 0.5 }
        PathAttribute { name: "iconOpacity"; value: 0.5 }

        PathLine {x: _rootCarousel.width / 2; y: _rootCarousel.height / 2 }
        PathAttribute { name: "iconScale"; value: 1.2 }
        PathAttribute { name: "iconOpacity"; value: 1 }

        PathLine {x: _rootCarousel.width; y: _rootCarousel.height / 2 }
    }
}
