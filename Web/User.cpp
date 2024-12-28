#include "User.h"

UserItem::UserItem()
    :MongoCore::Item("UserItem")
{

}

User::User(MongoCore::DB *db)
    :m_db( db )
{

}

MongoCore::DB *User::db() const
{
    return m_db;
}

void UserItem::setName(const std::string &nameSurname)
{
    append( "nameSurname" , nameSurname );
}

void UserItem::setUserName(const std::string &userName)
{
    append( "userName" , userName );
}

void UserItem::setPassword(const std::string &password)
{
    append( "password" , password );
}

std::string UserItem::nameSurname() const
{
    auto val = this->element("nameSurname");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }

    return "";
}

std::string UserItem::userName() const
{
    auto val = this->element("userName");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }

    return "";
}
