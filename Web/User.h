#ifndef USER_H
#define USER_H

#include "MongoCore/db.h"
#include "MongoCoreItem/item.h"


class UserItem : public MongoCore::Item
{
public:
    UserItem();

    void setName( const std::string &nameSurname );
    void setUserName( const std::string &userName );
    void setPassword( const std::string &password );


    std::string nameSurname() const;
    std::string userName() const;


};


class User : public UserItem
{
public:
    User( MongoCore::DB * db );

    MongoCore::DB *db() const;

private:
    MongoCore::DB* m_db;

};

#endif // USER_H
