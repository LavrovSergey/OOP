#include "ourtext.h"
#include "ui_ourtext.h"

OurText::OurText(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OurText)
{
    ui->setupUi(this);
}

OurText::~OurText()
{
    delete ui;
}
void OurText::Show(){
    QString t;
        QString filename="temp.txt";
            QFile file(filename);
             file.open(QIODevice::ReadOnly);
             QTextStream in(&file);
             while (!in.atEnd()){
                  t=in.readLine();
           }
             file.close();
        file.remove();

   ui-> label->setText(t);
}
