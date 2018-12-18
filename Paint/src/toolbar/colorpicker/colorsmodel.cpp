#include "colorsmodel.h"
#include <QColor>
#include <QDebug>

ColorsModel::ColorsModel(QObject *parent)
    : QAbstractListModel (parent)
{
   // default hardcoded colors
   m_colors = {
        QColor(Qt::black),
        QColor(Qt::gray),
        QColor(Qt::darkBlue),
        QColor(Qt::lightGray),
        QColor(Qt::green),
        QColor(Qt::red),
        QColor(Qt::blue),
        QColor(Qt::cyan),
        QColor(Qt::magenta),
        QColor(Qt::yellow),
        QColor(Qt::darkRed),
        QColor(Qt::darkGreen),
        QColor(Qt::darkCyan),
        QColor(Qt::darkMagenta),
        QColor(Qt::darkYellow),
        QColor(Qt::white)
    };
}

int ColorsModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return m_colors.count();
}

QVariant ColorsModel::data(const QModelIndex &index, const int role) const
{
    if (!index.isValid()) {
        qWarning() << "Invalid index requested for colors model!";
        return QVariant();
    }
    if (index.row() >= m_colors.size()) {
        qWarning() << "Requested index for colors model is more than colors count!";
        return QVariant();
    }

    if (role == Qt::DisplayRole) {
        return m_colors.at(index.row());
    }

    return QVariant();
}
