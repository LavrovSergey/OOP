#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include "windows.h"
#include "note.h"
#include <QMainWindow>
#include "ourtext.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   QList<Note> list;
   void Table(QString title);
    void Add();
   static void Add1();
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool compareFunction(const Note &n1, const Note &n2);
protected:// Метод для обработки native событий от ОС в Qt
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);
private slots:

  void on_AddNote_clicked();
    void on_Archive_clicked();

    void on_Show_clicked();
    void iconActivated(QSystemTrayIcon::ActivationReason reason);

private:
    void WriteTemp(QString text);
    void ReadTemp();
    Ui::MainWindow *ui;
     void AllNotes();
    QList<Note> archive;
    void InFile();
    QSystemTrayIcon *trayIcon;
};
#endif // MAINWINDOW_H
