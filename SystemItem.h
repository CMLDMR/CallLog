#ifndef SYSTEMITEM_H
#define SYSTEMITEM_H

#include "MongoCoreItem/item.h"

class SystemItem : public MongoCore::Item
{
public:
    static SystemItem *instance();



    bool loadConfig();
    void save();

    void setDefault();


    std::string httpAddress() const;
    std::string httpPort() const;
    std::string mongoUrl() const;
    std::string sqlDatabaseName() const;
    std::string sqlHostName() const;
    std::string sqlTableName() const;
    std::string sqlUserName() const;
    std::string sqlpassword() const;

private:
    SystemItem();

    static SystemItem *m_instance;
};

#endif // SYSTEMITEM_H
