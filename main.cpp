#include "MainWindow.h"

#include <mongocxx/instance.hpp>
#include <mongocxx/logger.hpp>

#include <QApplication>
#include <QDebug>
#include "SystemItem.h"

#include "WebServer.h"


class logger final : public mongocxx::logger {
public:
    explicit logger(std::ostream* stream) : _stream(stream) {}

    void operator()(mongocxx::log_level level,
                    bsoncxx::stdx::string_view domain,
                    bsoncxx::stdx::string_view message) noexcept override {
        if (level >= mongocxx::log_level::k_trace)
            return;
        // *_stream << "Level: " << level;
        *_stream << '[' << mongocxx::to_string(level) << '@' << domain << "] " << message << '\n';
        qDebug() << '[' << mongocxx::to_string(level).data() << '@' << domain.data() << "] " << message.data() ;
    }

private:
    std::ostream* const _stream;
};



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if( ! SystemItem::instance()->loadConfig() ) {
        qDebug() << "Restart After Configuration complete";
        return -1;
    }
    else {
        qDebug() << "httpAddress: " << SystemItem::instance()->httpAddress().data();
        qDebug() << "httpPort: " << SystemItem::instance()->httpPort().data();
        qDebug() << "mongoUrl: " << SystemItem::instance()->mongoUrl().data();
        qDebug() << "sqlDatabaseName: " << SystemItem::instance()->sqlDatabaseName().data();
        qDebug() << "sqlHostName: " << SystemItem::instance()->sqlHostName().data();
        qDebug() << "sqlTableName: " << SystemItem::instance()->sqlTableName().data();
        qDebug() << "sqlUserName: " << SystemItem::instance()->sqlUserName().data();
        qDebug() << "sqlpassword: " << SystemItem::instance()->sqlpassword().data();
    }

    mongocxx::instance instance{bsoncxx::stdx::make_unique<logger>(&std::cout)};


    auto webserver = new WebServer();

    webserver->startWebServerThread();

    MainWindow w;
    w.show();
    return a.exec();
}
