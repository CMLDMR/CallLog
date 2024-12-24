
#ifndef MONGOCORE_H
#define MONGOCORE_H

#ifndef Q_MOC_RUN
#include <mongocxx/database.hpp>
#endif





namespace MongoCore{

class DB;

class MongoCore
{
public:
    ~MongoCore();

    static MongoCore    *instance( mongocxx::client *client );
    static MongoCore    *instance();

    DB* db() const;

private:
    [[deprecated("use: MongoCore(mongocxx::client    *client) for Multi session;")]]
    MongoCore(const std::string & url = std::string());

    MongoCore(mongocxx::client    *client);

    mongocxx::client    *m_client { nullptr };
    mongocxx::database   m_db ;
    DB* mDB { nullptr };

    static MongoCore    *m_instance;

};

}




#endif // MONGOCORE_H
