#ifndef NOTETEXT_H
#define NOTETEXT_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class NoteText;
}

class NoteText : public QDialog
{
    Q_OBJECT

public:
    explicit NoteText(QWidget *parent = nullptr);
    ~NoteText();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NoteText *ui;
};

#endif // NOTETEXT_H
