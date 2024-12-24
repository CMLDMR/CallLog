#ifndef CDRTABLEMODEL_H
#define CDRTABLEMODEL_H

#include <QAbstractListModel>

class CDRTableModel : public QAbstractListModel
{
public:
    explicit CDRTableModel(QObject *parent = nullptr);
};

#endif // CDRTABLEMODEL_H
