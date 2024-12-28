#include "Logger.h"

#include <mutex>

#include <QDateTime>

Logger* Logger::m_logger { nullptr };
std::once_flag mOnceFlag;

Logger *Logger::instance(QObject *parent)
{

    std::call_once( mOnceFlag , [=,&parent](){
        m_logger = new Logger( parent );
    });

    return m_logger;
}

void Logger::appendError(const std::string &msg)
{
    appendLog( LogType::Error , msg );
}

void Logger::appendInfo(const std::string &msg)
{
    appendLog( LogType::Info , msg );
}

void Logger::appendWarn(const std::string &msg)
{
    appendLog( LogType::Warn , msg );
}

void Logger::clearLog()
{
    m_msgList.clear();
}

Logger::Logger(QObject *parent)
    : QObject{parent}
{}

void Logger::appendLog(const LogType type, const std::string &message)
{
    const auto dateTime = QDateTime::currentDateTime();
    QString msg = dateTime.date().toString("dd/MM/yy") + " " + dateTime.toString("hh:mm:ss");

    QString typeMsg = "None";
    switch ( type ) {
    case LogType::Error:
        typeMsg = "Error";
        break;
    case LogType::Info:
        typeMsg = "Info";
        break;
    case LogType::Warn:
        typeMsg = "None";
        break;
    default:
        break;
    }

    m_msgList.push_back( typeMsg + " : " + msg + " : " + QString::fromStdString( message ) );

    while( m_msgList.size() > 1000 ) {
        m_msgList.erase(m_msgList.begin());
    }

    Q_EMIT logged( m_msgList.back() );

}
