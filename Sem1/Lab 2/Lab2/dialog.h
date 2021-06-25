#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include "note.h"
#include <QTextStream>
#include<QFile>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
   void on_Button_clicked();
   void Temp(Note note);
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
