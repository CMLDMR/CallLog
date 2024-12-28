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

    void setStartDateTime(long long newStartJulianDay);

Q_SIGNALS:

    void readyQuery();


public Q_SLOTS:
    void startQuery();


private Q_SLOTS:
    void run();
    void retriveData();


private:
    QThread *m_thread;
    QSqlDatabase m_db;

    std::vector<CDRTableItem> m_queryList;

    long long m_startJulianDay;

    bool m_stop{ false };


};

#endif // SQLTONOSQL_H
