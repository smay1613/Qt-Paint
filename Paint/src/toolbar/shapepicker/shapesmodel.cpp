#include "shapesmodel.h"
#include <QDebug>

ShapesModel::ShapesModel(QObject *parent)
    : QAbstractListModel (parent),
      m_iconsPath("/resources/shapeicons/")
{
    m_shapesData = {
        std::make_pair(PaintTypes::ShapeType::Curve, "pencil.svg"),
        std::make_pair(PaintTypes::ShapeType::Line, "line.svg"),
        std::make_pair(PaintTypes::ShapeType::Rectangle, "rectangle.svg"),
        std::make_pair(PaintTypes::ShapeType::Circle, "ellipse.svg")
    };
    qRegisterMetaType<PaintTypes::ShapeType>("PaintTypes::ShapeType");
}

int ShapesModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_shapesData.count();
}

QVariant ShapesModel::data(const QModelIndex &index, const int role) const
{
    if (!index.isValid()) {
        qWarning() << "Invalid index requested for colors model!";
        return QVariant();
    }
    if (index.row() >= m_shapesData.size()) {
        qWarning() << "Requested index for colors model is more than colors count!";
        return QVariant();
    }

    switch(role) {
        case Qt::DisplayRole:
            return m_iconsPath + m_shapesData.at(index.row()).second;
        case ShapeRoles::Type:
            return QVariant::fromValue(m_shapesData.at(index.row()).first);
        default:
            return QVariant();
    }
}

QHash<int, QByteArray> ShapesModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::DisplayRole] = "display";
    roles[ShapeRoles::Type] = "type";
    return roles;
}
