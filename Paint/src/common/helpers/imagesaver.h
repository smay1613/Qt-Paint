#ifndef IMAGESAVER_H
#define IMAGESAVER_H
#include "src/common/drawhistory/drawhistory.h"

class ImageSaver
{
public:
    static bool save(DrawHistory& history, const QString& path);
};

#endif // IMAGESAVER_H
