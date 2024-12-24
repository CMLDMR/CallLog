#include "WebServer.h"
#include <QThread>

#include "SystemItem.h"


#include "Web/MainApplication.h"

using namespace Wt;

WebServer::WebServer(QObject *parent)
    : QObject{parent}
{

    m_webServerThread = new QThread( this );

    connect( m_webServerThread , &QThread::started , this, &WebServer::startWebServer );

}

void WebServer::startWebServerThread()
{
    this->m_webServerThread->start();
}

void WebServer::startWebServer()
{

    int argc1   = 6;
    auto argv1  = std::unique_ptr<char*[]>(new char*[argc1]);

    const std::string port          = "--http-port=" + SystemItem::instance()->httpPort();
    const std::string httpAddress   = "--http-address=" + SystemItem::instance()->httpAddress();

    argv1[0] = (char *) "Caller Log";
    argv1[1] = (char *) httpAddress.data();
    argv1[2] = (char *) port.data();
    argv1[3] = (char *) "--docroot=./docroot";
    argv1[4] = (char *) "--approot=./approot";
    argv1[5] = (char *) "--accesslog=-";


    try {
        m_server = new WServer( argc1 , argv1.get() , WTHTTP_CONFIGURATION );

        m_server->addEntryPoint(Wt::EntryPointType::Application , []( const Wt::WEnvironment &env ){
            return std::make_unique<MainApplication>( env );
        });

        m_server->start();

    } catch (const Wt::WServer::Exception &e) {
        return;
    } catch (const std::exception &e) {
        return;
    }
}
