#include "mainwindow.h"
#include <QList>
#include <QApplication>
#include "note.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QList<Note> list;
    w.show();
    return a.exec();
}
