#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>

class Logger : public QObject
{
    Q_OBJECT
public:


    static Logger *instance( QObject *parent = nullptr );

    void appendError( const std::string &msg );
    void appendInfo( const std::string &msg );
    void appendWarn( const std::string &msg );

    void clearLog();


Q_SIGNALS:
    void logged( const QString & );




private:
    explicit Logger(QObject *parent = nullptr);

    enum class LogType {
        Error,
        Warn,
        Info,
        none
    };


    void appendLog( const LogType type , const std::string &message );


    static Logger* m_logger;


    std::vector<QString> m_msgList;
};

#endif // LOGGER_H
