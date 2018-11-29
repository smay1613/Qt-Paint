#ifndef SHAPESMODEL_H
#define SHAPESMODEL_H
#include <QAbstractListModel>
#include <utility>
#include "../../common/painttypes.h"

class ShapesModel : public QAbstractListModel
{
public:
    // shape type and <image name>.<format>
    using ImageShapeTypePair = std::pair<const PaintTypes::ShapeType, const QString>;

    explicit ShapesModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent) const override;
    QVariant data(const QModelIndex &index, const int role) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
     QVector<ImageShapeTypePair> m_shapesData;
     const QString m_iconsPath;

     enum ShapeRoles {
         Type = Qt::UserRole + 1
     };
};

#endif // SHAPESMODEL_H
