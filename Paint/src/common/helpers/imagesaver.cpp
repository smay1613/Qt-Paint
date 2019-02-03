#include "imagesaver.h"
#include "src/toolbar/settings/viewsettings.h"
#include <QDebug>

bool ImageSaver::save(DrawHistory& history, const QString& path)
{
    QImage image {{static_cast<int>(ViewSettings::instance().resolutionWidth()),
                   static_cast<int>(ViewSettings::instance().resolutionHeight())},
                   QImage::Format_ARGB32};

    QPainter imagePainter (&image);

    image.fill(qRgba(255, 255, 255, 0));

    for (auto& command : history) {
        if (const auto& drawCommand = dynamic_cast<DrawCommand*>(command.get())) {
            const auto& storedPainter = drawCommand->painter();
            imagePainter.setPen(drawCommand->pen());
            drawCommand->setPainter(&imagePainter);
            drawCommand->execute();
            drawCommand->setPainter(storedPainter);
        }
    }

    QUrl pathUrl {path};
    return image.save(pathUrl.path());
}
