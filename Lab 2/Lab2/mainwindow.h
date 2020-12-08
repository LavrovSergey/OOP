#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "note.h"
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool compareFunction(const Note &n1, const Note &n2);

private slots:
    void on_AddNote_clicked();

    void on_Archive_clicked();

    void on_Show_clicked();

private:
    Ui::MainWindow *ui;
    QList<Note> list;
    QList<Note> archive;
    void InFile();
};
#endif // MAINWINDOW_H
