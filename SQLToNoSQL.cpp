#include "SQLToNoSQL.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDateTime>

#include <libssh/libssh.h>
#include <libssh/sftp.h>
#include <QDebug>
#include <fstream>
#include <fcntl.h>

#include "CDRTableItem.h"

#include "SystemItem.h"

#include "Logger.h"

SQLToNoSQL::SQLToNoSQL(QObject *parent)
    : QObject{parent}
{

    m_thread = new QThread( this );

    connect( m_thread , &QThread::started , this , &SQLToNoSQL::run );
}

void SQLToNoSQL::startQuery()
{
    if( m_stop )
        return;

    m_thread->start();
}

void SQLToNoSQL::run()
{

    QStringList drivers = QSqlDatabase::drivers();
    QString str = "Yüklü Sürücüler";
    for( const auto &item : drivers ) {
        str.append( " " + item );
    }
    Logger::instance()->appendInfo( str.toStdString() );


    // Veritabanı bağlantısı oluştur
    m_db = QSqlDatabase::addDatabase( SystemItem::instance()->sqlDatabaseName().data() );
    m_db.setHostName( SystemItem::instance()->sqlHostName().data() );       // MySQL sunucusu
    m_db.setDatabaseName(SystemItem::instance()->sqlTableName().data() ); // Veritabanı adı
    m_db.setUserName( SystemItem::instance()->sqlUserName().data() );      // MySQL kullanıcı adı
    m_db.setPassword(  SystemItem::instance()->sqlpassword().data() );             // MySQL şifresi

    // Veritabanına bağlanmayı dene
    if ( ! m_db.open() ) {
        Logger::instance()->appendError( "Veritabanı bağlantı hatası:" + m_db.lastError().text().toStdString() );
        return ;
    }

    retriveData();

}

void SQLToNoSQL::retriveData()
{


    // Veritabanına bağlanmayı dene
    if ( ! m_db.open() ) {
        Logger::instance()->appendError("Veritabanı bağlantı hatası:" + m_db.lastError().text().toStdString() );
        return ;
    }

    QSqlQuery query;

    // Tarih ve saat aralığını sorgulama
    // QString baslangicTarihSaat = "2024-11-17 00:00:00";
    // QString bitisTarihSaat = "2024-11-17 23:59:59";

    QString baslangicTarihSaat = QDate::fromJulianDay( m_startJulianDay ).toString("yyyy-MM-dd") + " 00:00:00";
    QString bitisTarihSaat = QDate::fromJulianDay( m_startJulianDay ).toString("yyyy-MM-dd") + " 23:59:59";

    Logger::instance()->appendInfo( QString("Start Date: %1 End Date: %2").arg( baslangicTarihSaat ).arg( bitisTarihSaat ).toStdString() );


    query.prepare("SELECT * FROM cdr WHERE calldate BETWEEN :baslangic AND :bitis");
    query.bindValue(":baslangic", baslangicTarihSaat);
    query.bindValue(":bitis", bitisTarihSaat);

    if ( ! query.exec() ) {  // Tablo adı yerine kendi tablonuzu yazın
        Logger::instance()->appendError("SQL sorgu hatası:" + query.lastError().text().toStdString() );
        return;
    }

    const auto record = query.record();

    const auto colCount = record.count();

    QStringList cols;

    for( int i = 0 ; i < colCount ; i++ ) {
        cols << record.fieldName( i );
    }

    m_queryList.clear();

    Logger::instance()->appendInfo( QString("Queried Size: %1").arg( query.size() ).toStdString() );

    while ( query.next() ) {

        CDRTableItem item;

        for( int i = 0 ; i < colCount ; i++ ) {
            if(  query.value( i ).type() == QVariant::Type::String ) {
                item.append( cols.at( i ).toStdString() , query.value( i ).toString().toStdString() );
            }
            else if ( query.value( i ).type() == QVariant::Type::Int ) {
                item.append( cols.at( i ).toStdString() , bsoncxx::types::b_int64 { query.value( i ).toInt() } );
            }
            else if ( query.value( i ).type() == QVariant::Type::LongLong ) {
                item.append( cols.at( i ).toStdString() , bsoncxx::types::b_int64 { query.value( i ).toLongLong() } );
            }
            else if ( query.value( i ).type() == QVariant::Type::ULongLong ) {
                item.append( cols.at( i ).toStdString() , bsoncxx::types::b_int64 { static_cast<int64_t>(query.value( i ).toULongLong()) } );
            }
            else if ( query.value( i ).type() == QVariant::Type::DateTime ) {
                item.append( cols.at( i ).toStdString() , bsoncxx::types::b_int64 { query.value( i ).toDateTime().toMSecsSinceEpoch() } );
            }
            else if ( query.value( i ).type() == QVariant::Type::UInt ) {
                item.append( cols.at( i ).toStdString() , bsoncxx::types::b_int64 { query.value( i ).toInt() } );
            }
        }

        m_queryList.push_back( item );

    }

    // if( m_queryList.size() )
    Q_EMIT readyQuery();

    if( ! m_stop )
        QTimer::singleShot( SystemItem::instance()->retrivePeriod() , this , &SQLToNoSQL::retriveData );

}

void SQLToNoSQL::setStartDateTime(long long newStartJulianDay)
{
    m_startJulianDay = newStartJulianDay;
}

std::vector<CDRTableItem> SQLToNoSQL::queryList() const
{
    return m_queryList;
}
