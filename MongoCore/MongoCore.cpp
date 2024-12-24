
#include "MongoCore.h"
#include <mongocxx/exception/exception.hpp>
#include <mongocxx/client.hpp>
#include "db.h"

#include <stdexcept>

#include <QObject>


// inline const char* _url = "mongodb://username:password@127.0.0.1:27018/?authSource=SAP";
inline const char* _url = "mongodb://localhost:27017";
inline const char* databasename =  "Spartan" ;


MongoCore::MongoCore    *MongoCore::MongoCore::m_instance = nullptr;
std::once_flag  mFlagInstance;

MongoCore::MongoCore::MongoCore(const std::string &url)
{
    try {
        std::string mongoUrl = url.empty() ? _url : url;
        m_client = new mongocxx::client(mongocxx::uri(mongoUrl));
    } catch (mongocxx::exception &e) {
        std::cout << __LINE__ << ":"<< __FILE__ << " " << e.what() << "\n";
        return;
    }

    m_db = m_client->database( databasename );

    mDB = new DB(&m_db);
}

MongoCore::MongoCore::MongoCore(mongocxx::v_noabi::client *client)
    :m_client(client)
{
    m_db = m_client->database( databasename );

    mDB = new DB(&m_db);
}

MongoCore::MongoCore::~MongoCore()
{

}

MongoCore::MongoCore *MongoCore::MongoCore::instance(mongocxx::v_noabi::client *m_client)
{
    if( m_instance ) {
        // if( ! m_instance->m_client ) {
            m_instance = new MongoCore( m_client );
        // }
    }else{
        m_instance = new MongoCore( m_client );
    }

    return m_instance;

}

MongoCore::MongoCore *MongoCore::MongoCore::instance()
{
    if( ! m_instance ) {
        throw std::runtime_error( QObject::tr("MongoCore did not initialized. Please connect to db!").toStdString() );
        return nullptr;
    }
    if( ! m_instance->m_client ) {
        throw std::runtime_error( QObject::tr("MongoCore Client did not initialized. Please set mongocxx::client before!").toStdString() );
    }
    return m_instance;
}



namespace MongoCore {
DB *MongoCore::db() const
{
    if( m_client )
        return mDB;
    else
        return nullptr;
}

}
