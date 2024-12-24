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

SQLToNoSQL::SQLToNoSQL(QObject *parent)
    : QObject{parent}
{


    QStringList drivers = QSqlDatabase::drivers();
    qDebug() << "Yüklü sürücüler:" << drivers;

    // Veritabanı bağlantısı oluştur
    m_db = QSqlDatabase::addDatabase( SystemItem::instance()->sqlDatabaseName().data() );
    m_db.setHostName( SystemItem::instance()->sqlHostName().data() );       // MySQL sunucusu
    m_db.setDatabaseName(SystemItem::instance()->sqlTableName().data() ); // Veritabanı adı
    m_db.setUserName( SystemItem::instance()->sqlUserName().data() );      // MySQL kullanıcı adı
    m_db.setPassword(  SystemItem::instance()->sqlpassword().data() );             // MySQL şifresi

    // Veritabanına bağlanmayı dene
    if (!m_db.open()) {
        qCritical() << "Veritabanı bağlantı hatası:" << m_db.lastError().text();
        return ;
    }

}

void SQLToNoSQL::startQuery()
{

    // Veritabanına bağlanmayı dene
    if (!m_db.open()) {
        qCritical() << "Veritabanı bağlantı hatası:" << m_db.lastError().text();
        return ;
    }

    QSqlQuery query;

    // Tarih ve saat aralığını sorgulama
    QString baslangicTarihSaat = "2024-11-17 00:00:00";
    QString bitisTarihSaat = "2024-11-17 23:59:59";

    // QString baslangicTarihSaat = QDate::currentDate().toString("yyyy-MM-dd") + " 00:00:00";
    // QString bitisTarihSaat = QDate::currentDate().toString("yyyy-MM-dd") + " 23:59:59";

    query.prepare("SELECT * FROM cdr WHERE calldate BETWEEN :baslangic AND :bitis");
    query.bindValue(":baslangic", baslangicTarihSaat);
    query.bindValue(":bitis", bitisTarihSaat);

    if ( ! query.exec() ) {  // Tablo adı yerine kendi tablonuzu yazın
        qCritical() << "SQL sorgu hatası:" << query.lastError().text();
        return;
    }

    const auto record = query.record();

    const auto colCount = record.count();

    QStringList cols;

    for( int i = 0 ; i < colCount ; i++ ) {
        cols << record.fieldName( i );
    }

    m_queryList.clear();

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

    if( m_queryList.size() )
        Q_EMIT readyQuery();


}

std::vector<CDRTableItem> SQLToNoSQL::queryList() const
{
    return m_queryList;
}
