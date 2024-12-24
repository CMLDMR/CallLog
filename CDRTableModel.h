#ifndef CDRTABLEMODEL_H
#define CDRTABLEMODEL_H

#include <QAbstractListModel>
#include "CDRTableItem.h"

class SQLToNoSQL;

class CDRTableModel : public QAbstractListModel
{
public:
    explicit CDRTableModel(QObject *parent = nullptr);

    // QAbstractItemModel interface
public:
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;


public Q_SLOTS:
    void updateQueryModel();


private Q_SLOTS:
    void queriedModel();
private:
    std::vector<CDRTableItem> m_list;

    SQLToNoSQL *m_querier;

    QStringList m_colsName;

    // QAbstractItemModel interface
public:
    virtual int columnCount(const QModelIndex &parent) const override;

    // QAbstractItemModel interface
public:
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
};

#endif // CDRTABLEMODEL_H
