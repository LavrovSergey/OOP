#ifndef OURTEXT_H
#define OURTEXT_H

#include <QDialog>
#include "note.h"
#include <QTextStream>
#include<QFile>
namespace Ui {
class OurText;
}

class OurText : public QDialog
{
    Q_OBJECT

public:
     void Show();
    explicit OurText(QWidget *parent = nullptr);
    ~OurText();

private:
    Ui::OurText *ui;

};

#endif // OURTEXT_H
