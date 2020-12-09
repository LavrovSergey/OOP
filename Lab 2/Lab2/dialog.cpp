#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_Button_clicked()
{
    QString choise;
    if(ui->R1->isChecked()){choise="Робочі"; }
    else if(ui->R2->isChecked()){choise="Відпочинок";}
    else if(ui->R3->isChecked()){choise="Персональні"; }
    else if(ui->R4->isChecked()){choise="Ідеї/Плани"; }
   Note note(ui->Title->text(), ui->Text->toPlainText(), choise);
   Temp(note);
   ui->Title->clear();
   ui->Text->clear();
}
void Dialog::Temp(Note note){
    QString filename="temp.txt";
        QFile file(filename);
       file.open(QIODevice::Append);
       QTextStream out(&file);
                out<<note.GetTitle()<<Qt::endl;
                 out<<note.GetText()<<Qt::endl;
                  out<<note.GetDate().toString()<<Qt::endl;
                  out<<note.GetType()<<Qt::endl;
      file.close();
}
