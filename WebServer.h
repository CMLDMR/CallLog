#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <QObject>
#include <Wt/WServer.h>


class MainApplication;

class WebServer : public QObject
{
    Q_OBJECT
public:
    explicit WebServer(QObject *parent = nullptr);

    void startWebServerThread();

Q_SIGNALS:

private Q_SLOTS:

    void startWebServer();


private:

    QThread *m_webServerThread;
    MainApplication *m_mainApplication;
    Wt::WServer *m_server;

};

#endif // WEBSERVER_H
