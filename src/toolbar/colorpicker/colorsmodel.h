#ifndef COLORSMODEL_H
#define COLORSMODEL_H
#include <QAbstractListModel>
#include <QColor>

class ColorsModel : public QAbstractListModel
{
public:
    ColorsModel(QObject*);

    int rowCount(const QModelIndex&) const override;
    QVariant data(const QModelIndex &index, int role) const override;

private:
    QVector<QColor> m_colors;
};

#endif // COLORSMODEL_H
