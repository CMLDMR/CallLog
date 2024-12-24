#ifndef SQLTONOSQL_H
#define SQLTONOSQL_H

#include <QObject>

class SQLToNoSQL : public QObject
{
    Q_OBJECT
public:
    explicit SQLToNoSQL(QObject *parent = nullptr);

signals:
};

#endif // SQLTONOSQL_H
