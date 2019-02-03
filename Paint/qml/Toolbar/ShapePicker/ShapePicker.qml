import QtQuick 2.9
import Common 1.0
import ToolBarPlugin 1.0

ToolBarItem {
    id: _rootPicker
    contentItem: Component {
        Carousel {
            id: _carousel
            width: (currentItem.width + 20)* pathItemCount
            height: _rootPicker.height

            model: _model

            delegate: ShapeBox {
                id: _shapeBox
                scale: PathView.iconScale ? PathView.iconScale : 1
                opacity: PathView.iconOpacity ? PathView.iconOpacity : 1
                onRequestActivate: {
                    _carousel.currentIndex = index;
                }
            }

            onCurrentItemChanged: {
                PaintSettings.activeShape = currentItem.shapeType;
            }

            ShapesModel {
                id: _model
            }
        }
    }
}
