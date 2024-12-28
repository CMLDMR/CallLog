#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include "CDRTableItem.h"
#include "CDRTableModel.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

#include <libssh/libssh.h>
#include <libssh/sftp.h>
#include <QDebug>
#include <fstream>
#include <fcntl.h>

#include "SystemItem.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    try {
        m_mongoClient = new mongocxx::client(mongocxx::uri( SystemItem::instance()->mongoUrl() ) );
    } catch ( mongocxx::exception &e) {
        return;
    }

    m_database = m_mongoClient->database( "CallerLog" );
    m_db = new MongoCore::DB( &m_database );


    ui->startDateEdit->setDate( QDate::currentDate() );
    ui->startDateEdit->setTime( QTime( 0 , 0 , 0 ) );

    m_cdrTableModel = new CDRTableModel( m_db , ui->tableView );

    ui->tableView->setModel( m_cdrTableModel );

    connect( ui->startDateEdit , &QDateTimeEdit::dateTimeChanged , this , [=]( const QDateTime &dateTime ){
        ui->endDateEdit->setDate( QDate::fromJulianDay( dateTime.date().toJulianDay() ) );
        ui->endDateEdit->setTime( QTime(23,59,59 ) );
        m_cdrTableModel->setStartDate( dateTime.date().toJulianDay() );
    });


    connect( ui->refreshPushButton , &QPushButton::clicked , this , [=]( ){
        m_cdrTableModel->updateQueryModel();
    });


    m_cdrTableModel->updateQueryModel();



    // QStringList drivers = QSqlDatabase::drivers();
    // qDebug() << "Yüklü sürücüler:" << drivers;

    // // Veritabanı bağlantısı oluştur
    // QSqlDatabase db = QSqlDatabase::addDatabase("QMARIADB");
    // db.setHostName("192.168.1.104");       // MySQL sunucusu
    // db.setDatabaseName("asteriskcdrdb"); // Veritabanı adı
    // db.setUserName("freed");      // MySQL kullanıcı adı
    // db.setPassword("123456");             // MySQL şifresi

    // // Veritabanına bağlanmayı dene
    // if (!db.open()) {
    //     qCritical() << "Veritabanı bağlantı hatası:" << db.lastError().text();
    //     return ;
    // }

    // qDebug() << "Veritabanı bağlantısı başarılı!";

    // // SQL sorgusu hazırla ve çalıştır
    // QSqlQuery query;

    // // Tarih ve saat aralığını sorgulama
    // QString baslangicTarihSaat = "2024-11-17 17:55:10";
    // QString bitisTarihSaat = "2024-11-17 17:56:12";

    // query.prepare("SELECT * FROM cdr WHERE calldate BETWEEN :baslangic AND :bitis");
    // query.bindValue(":baslangic", baslangicTarihSaat);
    // query.bindValue(":bitis", bitisTarihSaat);

    // if (!query.exec()) {  // Tablo adı yerine kendi tablonuzu yazın
    //     qCritical() << "SQL sorgu hatası:" << query.lastError().text();
    //     return;
    // }


    // // if (!query.exec("SELECT * FROM cdr")) {  // Tablo adı yerine kendi tablonuzu yazın
    // //     qCritical() << "SQL sorgu hatası:" << query.lastError().text();
    // //     return;
    // // }

    // const auto record = query.record();

    // qDebug() << "Table Color = " << record.count();
    // const auto colCount = record.count();

    // QStringList cols;

    // for( int i = 0 ; i < colCount ; i++ ) {
    //     qDebug() << i << record.fieldName( i );
    //     cols << record.fieldName( i );
    // }

    // std::vector<CDRTableItem> itemList;

    // int index = 0;
    // // Sonuçları al ve yazdır
    // while (query.next()) {
    //     // QString id = query.value(0).toString();  // İlk sütun
    //     // QString name = query.value(1).toString(); // İkinci sütun
    //     // QString three = query.value(3).toString(); // İkinci sütun

    //     CDRTableItem item;
    //     QStringList strList;
    //     for( int i = 0 ; i < colCount ; i++ ) {
    //         // strList << query.value( i ).typeName() << cols.at( i ) << query.value( i ).toString() << "----";

    //         if(  query.value( i ).type() == QVariant::Type::String ) {
    //             item.append( cols.at( i ).toStdString() , query.value( i ).toString().toStdString() );
    //         }
    //         else if ( query.value( i ).type() == QVariant::Type::Int ) {
    //             item.append( cols.at( i ).toStdString() , bsoncxx::types::b_int64 { query.value( i ).toInt() } );
    //         }
    //         else if ( query.value( i ).type() == QVariant::Type::LongLong ) {
    //             item.append( cols.at( i ).toStdString() , bsoncxx::types::b_int64 { query.value( i ).toLongLong() } );
    //         }
    //         else if ( query.value( i ).type() == QVariant::Type::ULongLong ) {
    //             item.append( cols.at( i ).toStdString() , bsoncxx::types::b_int64 { static_cast<int64_t>(query.value( i ).toULongLong()) } );
    //         }
    //         else if ( query.value( i ).type() == QVariant::Type::DateTime ) {
    //             item.append( cols.at( i ).toStdString() , bsoncxx::types::b_int64 { query.value( i ).toDateTime().toMSecsSinceEpoch() } );
    //         }
    //         else if ( query.value( i ).type() == QVariant::Type::UInt ) {
    //             item.append( cols.at( i ).toStdString() , bsoncxx::types::b_int64 { query.value( i ).toInt() } );
    //         }
    //     }

    //     qDebug() << bsoncxx::to_json( item.view() ).data() ;
    //     // strList << query.value(0).typeName() << query.value(0).toString();


    //     index++;

    //     qDebug() << index << strList;
    // }

    // db.close();


    // downloadFile("192.168.1.104","root","1","/var/spool/asterisk/monitor/2024/11/17/internal-1100-1101-20241117-164137-1731861697.2.wav","./internal-1100-1101-20241117-164137-1731861697.2.wav");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::downloadFile(const QString &hostname, const QString &username, const QString &password,
                              const QString &remotePath, const QString &localPath) {
    ssh_session session = ssh_new();
    if (!session) {
        qCritical() << "SSH oturumu oluşturulamadı!";
        return;
    }

    // SSH ayarları
    ssh_options_set(session, SSH_OPTIONS_HOST, hostname.toStdString().c_str());
    ssh_options_set(session, SSH_OPTIONS_USER, username.toStdString().c_str());

    // Bağlantı kur
    if (ssh_connect(session) != SSH_OK) {
        qCritical() << "SSH bağlantı hatası:" << ssh_get_error(session);
        ssh_free(session);
        return;
    }

    // Kimlik doğrulama
    if (ssh_userauth_password(session, nullptr, password.toStdString().c_str()) != SSH_AUTH_SUCCESS) {
        qCritical() << "Kimlik doğrulama hatası:" << ssh_get_error(session);
        ssh_disconnect(session);
        ssh_free(session);
        return;
    }

    // SFTP oturumu başlat
    sftp_session sftp = sftp_new(session);
    if (!sftp) {
        qCritical() << "SFTP oturumu oluşturulamadı:" << ssh_get_error(session);
        ssh_disconnect(session);
        ssh_free(session);
        return;
    }

    if (sftp_init(sftp) != SSH_OK) {
        qCritical() << "SFTP oturumu başlatılamadı:" << sftp_get_error(sftp);
        sftp_free(sftp);
        ssh_disconnect(session);
        ssh_free(session);
        return;
    }

    // Uzak dosyayı aç
    sftp_file file = sftp_open( sftp, remotePath.toStdString().c_str() , O_RDONLY , 0);
    if (!file) {
        qCritical() << "Uzak dosya açılamadı:" << sftp_get_error(sftp);
        sftp_free(sftp);
        ssh_disconnect(session);
        ssh_free(session);
        return;
    }

    // Yerel dosyayı oluştur
    std::ofstream localFile(localPath.toStdString(), std::ios::binary);
    if (!localFile.is_open()) {
        qCritical() << "Yerel dosya oluşturulamadı!";
        sftp_close(file);
        sftp_free(sftp);
        ssh_disconnect(session);
        ssh_free(session);
        return;
    }

    // Dosyayı indir
    char buffer[4096];
    int bytesRead;
    while ((bytesRead = sftp_read(file, buffer, sizeof(buffer))) > 0) {
        localFile.write(buffer, bytesRead);
    }

    if (bytesRead < 0) {
        qCritical() << "Dosya okuma hatası:" << sftp_get_error(sftp);
    } else {
        qDebug() << "Dosya başarıyla indirildi!";
    }

    // Kaynakları temizle
    localFile.close();
    sftp_close(file);
    sftp_free(sftp);
    ssh_disconnect(session);
    ssh_free(session);

}
