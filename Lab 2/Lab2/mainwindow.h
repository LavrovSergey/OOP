#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include "windows.h"
#include "note.h"
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     void on_AddNote_clicked();
    void Add();
   static void Add1();
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool compareFunction(const Note &n1, const Note &n2);
protected:// Метод для обработки native событий от ОС в Qt
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);
private slots:


    void on_Archive_clicked();

    void on_Show_clicked();
    void iconActivated(QSystemTrayIcon::ActivationReason reason);

private:
    Ui::MainWindow *ui;
    QList<Note> list;
    QList<Note> archive;
    void InFile();
    QSystemTrayIcon *trayIcon;
};
#endif // MAINWINDOW_H
