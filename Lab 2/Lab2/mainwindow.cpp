#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "note.h"
#include <QTextStream>
#include<QFile>
#include "notetext.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
     ui->setupUi(this);


     QString filename;
     for(int i =0;i<4;i++){
         if(i==0){filename="Work.txt";}
         else if(i==1){filename="Rest.txt";}
         else if(i==2){filename="Personal.txt";}
         else if(i==3){filename="Plans.txt";}
         QFile file(filename);
          file.open(QIODevice::ReadOnly);
          QTextStream in(&file);
          while (!in.atEnd()){
              QString title=in.readLine();
               QString text=in.readLine();
                QString date=in.readLine();
                QString type=in.readLine();
                qDebug(title.toStdString().c_str());
                qDebug(text.toStdString().c_str());
                qDebug(date.toStdString().c_str());
                qDebug(type.toStdString().c_str());
              Note note(title,text ,type );
              list.append(note);
          }
          file.close();
     }
     QString choise[4]={"Робочі","Відпочинок","Персональні","Ідеї/Плани"};
     for(int i=0;i<4;i++)
     {
         QListWidgetItem* cur=new QListWidgetItem();
         cur->setText(choise[i]);
         ui->Screen->addItem(cur);
     }
    qSort(list.begin(), list.end(), Note::compareFunction);
    for (auto begin = list.begin(); begin != list.end(); begin++)
        {
            QListWidgetItem *newItem = new QListWidgetItem();
            newItem->setText( begin->GetTitle() );
            ui->TitleList->addItem(newItem);
        }

}

MainWindow::~MainWindow()
{
    //запись в файл
   delete ui;
    InFile();

}
void MainWindow::InFile(){
    QTextStream out(stdout);
    QString filename;
    for(int i=0;i<4;i++){
        if(i==0){filename="Work.txt";}
        else if(i==1){filename="Rest.txt";}
        else if(i==2){filename="Personal.txt";}
        else if(i==3){filename="Plans.txt";}
        QFile file(filename);
       file.open(QIODevice::WriteOnly);
       QTextStream out(&file);
        for (auto begin = list.begin(); begin != list.end(); begin++){
            if(begin->GetType()=="Робочі" && i==0){
                out<<begin->GetTitle()<<Qt::endl;
                 out<<begin->GetText()<<Qt::endl;
                  out<<begin->GetDate().toString()<<Qt::endl;
                  out<<begin->GetType()<<Qt::endl;
            }
            else if(begin->GetType()=="Відпочинок"&& i==1){
                out<<begin->GetTitle()<<Qt::endl;
                 out<<begin->GetText()<<Qt::endl;
                  out<<begin->GetDate().toString()<<Qt::endl;
                  out<<begin->GetType()<<Qt::endl;
            }
            else if(begin->GetType()=="Персональні"&& i==2){
                out<<begin->GetTitle()<<Qt::endl;
                 out<<begin->GetText()<<Qt::endl;
                  out<<begin->GetDate().toString()<<Qt::endl;
                  out<<begin->GetType()<<Qt::endl;
            }
            else if(begin->GetType()=="Ідеї/Плани"&& i==3){
                out<<begin->GetTitle()<<Qt::endl;
                 out<<begin->GetText()<<Qt::endl;
                  out<<begin->GetDate().toString()<<Qt::endl;
                  out<<begin->GetType()<<Qt::endl;
            }

        }
      file.close();
    }
}

void MainWindow::on_AddNote_clicked()
{
    QListWidgetItem *newItem=new QListWidgetItem;
    newItem->setText(ui->NoteTitle->text());
    ui->TitleList->insertItem(0,newItem);

    QString choise;
    if(ui->R1->isChecked()){choise="Робочі"; }
    else if(ui->R2->isChecked()){choise="Відпочинок";}
    else if(ui->R3->isChecked()){choise="Персональні"; }
    else if(ui->R1->isChecked()){choise="Ідеї/Плани"; }


   Note note(ui->NoteTitle->text(), ui->NoteText->toPlainText(), choise);
    list.insert(0, note);
    ui->NoteTitle->clear();
    ui->NoteText->clear();
}


void MainWindow::on_Archive_clicked()
{
    QListWidgetItem* cur=ui->TitleList->currentItem();
    int id=ui->TitleList->row(cur);
    delete ui->TitleList->takeItem(id);
    archive.append(list.at(id));
    list.removeAt(id);
}



void MainWindow::on_Show_clicked()
{
     QString id;
    auto* SCR=ui->Screen;
        if(auto* src_item=SCR->item(SCR->currentRow()))
        {
            id= src_item->text();
            SCR->clear();
            src_item=nullptr;

            for (auto begin = list.begin(); begin != list.end(); begin++)
            {
                if(id==begin->GetType())
                {
                    QListWidgetItem *cur=new QListWidgetItem;
                    cur->setText(begin->GetTitle());
                    SCR->insertItem(0,cur);
                }
            }
        }

        if(auto* src_item=SCR->item(SCR->currentRow()))
        {
            QString index= src_item->text();
            SCR->clear();
            src_item=nullptr;

            for (auto begin = list.begin(); begin != list.end(); begin++)
            {
                if(index==begin->GetTitle() && id==begin->GetType())
                {
                    QListWidgetItem *cur=new QListWidgetItem;
                    cur->setText(begin->GetText());
                    SCR->insertItem(0,cur);
                }
            }
        }

}