#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QShortcut>
#include <QMainWindow>
#include <QSystemTrayIcon>
#include "windows.h"
#include "note.h"
#include <QMainWindow>
#include "ourtext.h"
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QAction>
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
protected:
    /* Виртуальная функция родительского класса в нашем классе
     * переопределяется для изменения поведения приложения,
     *  чтобы оно сворачивалось в трей, когда мы этого хотим
     */
    void closeEvent(QCloseEvent * event);
private slots:

  void on_AddNote_clicked();
    void on_Archive_clicked();
    void slotShortcutCtrlD();
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
    QShortcut       *keyCtrlD;
};
#endif // MAINWINDOW_H
