#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "MongoCore/db.h"
#include <mongocxx/client.hpp>
#include <mongocxx/database.hpp>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class CDRTableModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void downloadFile( const QString &hostname, const QString &username, const QString &password,
                      const QString &remotePath, const QString &localPath );

private:
    Ui::MainWindow *ui;


    CDRTableModel   *m_cdrTableModel;

    mongocxx::client* m_mongoClient { nullptr };
    mongocxx::database m_database;;

    MongoCore::DB *m_db;
};
#endif // MAINWINDOW_H
