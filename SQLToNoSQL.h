#ifndef SQLTONOSQL_H
#define SQLTONOSQL_H

#include "CDRTableItem.h"
#include <QObject>
#include <QThread>
#include <QTimer>

#include <QSqlDatabase>

class SQLToNoSQL : public QObject
{
    Q_OBJECT
public:
    explicit SQLToNoSQL(QObject *parent = nullptr);

    std::vector<CDRTableItem> queryList() const;

Q_SIGNALS:

    void readyQuery();


public Q_SLOTS:
    void startQuery();


private:
    QSqlDatabase m_db;

    std::vector<CDRTableItem> m_queryList;

};

#endif // SQLTONOSQL_H
