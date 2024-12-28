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

#include "Logger.h"
#include "SystemItem.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Logger::instance( this );

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

    connect( ui->startDateEdit , &QDateTimeEdit::dateTimeChanged , this , [=, this]( const QDateTime &dateTime ){
        ui->endDateEdit->setDate( QDate::fromJulianDay( dateTime.date().toJulianDay() ) );
        ui->endDateEdit->setTime( QTime(23,59,59 ) );
        m_cdrTableModel->setStartDate( dateTime.date().toJulianDay() );
    });

    ui->endDateEdit->setDate( QDate::fromJulianDay( ui->startDateEdit->date().toJulianDay() ) );
    ui->endDateEdit->setTime( QTime(23,59,59 ) );
    m_cdrTableModel->setStartDate( ui->startDateEdit->date().toJulianDay() );


    connect( ui->refreshPushButton , &QPushButton::clicked , this , [=, this]( ){
        m_cdrTableModel->updateQueryModel();
    });


    connect( ui->openLogCheckBox , &QCheckBox::stateChanged , this , [=, this]( const int state ){
        ui->logPlainTextEdit->setHidden( state != 2 );
    });

    ui->logPlainTextEdit->setHidden( true );
    ui->openLogCheckBox->setChecked( false );


    m_cdrTableModel->updateQueryModel();


    connect( Logger::instance() , &Logger::logged , [=,this]( const QString &msg ) {
        ui->logPlainTextEdit->appendPlainText( msg );
    } );

    connect( ui->clearLogPushButton , &QPushButton::clicked , [=, this](){
        ui->logPlainTextEdit->clear();
        Logger::instance()->clearLog();
    });



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
