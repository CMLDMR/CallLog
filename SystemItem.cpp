#include "SystemItem.h"
#include <mutex>
#include <QFile>
#include <QByteArray>

SystemItem   *SystemItem::m_instance = nullptr;
std::once_flag  mFlagInstance;

SystemItem *SystemItem::instance()
{
    std::call_once( mFlagInstance , [=](){
        m_instance = new SystemItem();
    });

    return m_instance;
}

bool SystemItem::loadConfig()
{
    QFile file("systemConfig.json");

    if( !file.exists() ) {
        save();
        return false;
    }

    if( file.open( QIODevice::ReadOnly ) ) {

        auto ar = file.readAll();

        try {
            const auto view = bsoncxx::from_json( ar.data() );
            this->setDocumentView( view );
        } catch (bsoncxx::exception &e) {
            return false;
        }
        file.close();
    }
    else{
        return false;
    }

    return true;
}

void SystemItem::save()
{
    if( this->view().empty() ) {
        this->setDefault();
    }

    QFile file("systemConfig.json");

    if( file.exists() ) {
        if( ! QFile::remove("systemConfig.json") ) {
            return;
        }
    }

    if( file.open( QIODevice::ReadWrite ) ) {
        file.write( bsoncxx::to_json(this->view()).data() );
        file.close();
    }
}

void SystemItem::setDefault()
{
    this->clear();
    this->append("httpAddress","127.0.0.1");
    this->append("httpPort","8080");
    this->append("mongoUrl","mongo://localhost:21017");
    this->append("sqlDatabaseName","QMARIADB");
    this->append("sqlHostName","192.168.1.104");
    this->append("sqlTableName","asteriskcdrdb");
    this->append("sqlUserName","user");
    this->append("sqlpassword","123456");

    this->save();
}

std::string SystemItem::httpAddress() const
{
    auto val = this->element("httpAddress");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

std::string SystemItem::httpPort() const
{
    auto val = this->element("httpPort");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

std::string SystemItem::mongoUrl() const
{
    auto val = this->element("mongoUrl");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

std::string SystemItem::sqlDatabaseName() const
{
    auto val = this->element("sqlDatabaseName");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

std::string SystemItem::sqlHostName() const
{
    auto val = this->element("sqlHostName");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

std::string SystemItem::sqlTableName() const
{
    auto val = this->element("sqlTableName");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

std::string SystemItem::sqlUserName() const
{
    auto val = this->element("sqlUserName");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

std::string SystemItem::sqlpassword() const
{
    auto val = this->element("sqlpassword");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

SystemItem::SystemItem()
    :MongoCore::Item("systemItem")
{

}
