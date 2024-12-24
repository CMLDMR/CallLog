#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
};
#endif // MAINWINDOW_H
