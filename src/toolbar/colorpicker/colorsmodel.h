#ifndef COLORSMODEL_H
#define COLORSMODEL_H
#include <QAbstractListModel>
#include <QColor>

class ColorsModel : public QAbstractListModel
{
public:
    explicit ColorsModel(QObject* parent);

    int rowCount(const QModelIndex&) const override;
    QVariant data(const QModelIndex &index, const int role) const override;

private:
    QVector<QColor> m_colors;
};

#endif // COLORSMODEL_H
