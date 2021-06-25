#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "note.h"
#include <QTextStream>
#include<QFile>
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
     ui->setupUi(this);
     keyCtrlD = new QShortcut(this); // Инициализируем объект
         keyCtrlD->setKey(Qt::CTRL | Qt::Key_D); // Устанавливаем сочетание клавиш
         // подключаем обработчик нажатия клавиши
         connect(keyCtrlD, SIGNAL(activated()), this, SLOT(slotShortcutCtrlD()));

             trayIcon = new QSystemTrayIcon(this);
             trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_ComputerIcon));
             trayIcon->setToolTip("Tray Program" "\n"
                                  "Работа со сворачиванием программы трей");
             /* После чего создаем контекстное меню из двух пунктов*/
             QMenu * menu = new QMenu(this);
             QAction * viewWindow = new QAction(("Развернуть окно"), this);
             QAction * quitAction = new QAction(("Выход"), this);

             /* подключаем сигналы нажатий на пункты меню к соответсвующим слотам.
              * Первый пункт меню разворачивает приложение из трея,
              * а второй пункт меню завершает приложение
              * */
             connect(viewWindow, SIGNAL(triggered()), this, SLOT(show()));
             connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

             menu->addAction(viewWindow);
             menu->addAction(quitAction);

             /* Устанавливаем контекстное меню на иконку
              * и показываем иконку приложения в трее
              * */
             trayIcon->setContextMenu(menu);
             trayIcon->show();

             /* Также подключаем сигнал нажатия на иконку к обработчику
              * данного нажатия
              * */
             connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
                     this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
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
              Note note(title,text ,type );
              list.append(note);
          }
          file.close();
     }
     AllNotes();
    std::sort(list.begin(), list.end(), Note::compareFunction);
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
void MainWindow::closeEvent(QCloseEvent * event)
{
    /* Если окно видимо и чекбокс отмечен, то завершение приложения
     * игнорируется, а окно просто скрывается, что сопровождается
     * соответствующим всплывающим сообщением
     */
    if(this->isVisible() && ui->trayCheckBox->isChecked()){
        event->ignore();
        this->hide();
        QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);

        trayIcon->showMessage("Tray Program",
                              ("Приложение свернуто в трей. Для того чтобы, "
                                     "развернуть окно приложения, щелкните по иконке приложения в трее"),
                              icon,
                              2000);
    }
}
/* Метод, который обрабатывает нажатие на иконку приложения в трее
 * */
void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason){
    case QSystemTrayIcon::Trigger:
        /* Событие игнорируется в том случае, если чекбокс не отмечен
         * */
        if(ui->trayCheckBox->isChecked()){
            /* иначе, если окно видимо, то оно скрывается,
             * и наоборот, если скрыто, то разворачивается на экран
             * */
            if(!this->isVisible()){
                this->show();
            } else {
                this->hide();
            }
        }
        break;
    default:
        break;
    }
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
void MainWindow::slotShortcutCtrlD()
{
    Dialog add;
      add.setModal(true);
      add.exec();
      ReadTemp();
}

void MainWindow::ReadTemp(){
    QString filename="temp.txt";
        QFile file(filename);
         file.open(QIODevice::ReadOnly);
         QTextStream in(&file);
         while (!in.atEnd()){
             QString title=in.readLine();
              QString text=in.readLine();
               QString date=in.readLine();
               QString type=in.readLine();
             Note note(title,text ,type );
             list.insert(0,note);
             Table(title);
         }
         file.close();
    file.remove();

}


void MainWindow::on_AddNote_clicked()
{
    Add();
}
void MainWindow::Add(){
   Table(ui->NoteTitle->text());

    QString choise;
    if(ui->R1->isChecked()){choise="Робочі"; }
    else if(ui->R2->isChecked()){choise="Відпочинок";}
    else if(ui->R3->isChecked()){choise="Персональні"; }
    else if(ui->R4->isChecked()){choise="Ідеї/Плани"; }


   Note note(ui->NoteTitle->text(), ui->NoteText->toPlainText(), choise);
    list.insert(0, note);
    ui->NoteTitle->clear();
    ui->NoteText->clear();
}
void MainWindow::Table(QString title){
    QListWidgetItem *newItem=new QListWidgetItem;
    newItem->setText(title);
    ui->TitleList->insertItem(0,newItem);
}
void MainWindow::on_Archive_clicked()
{
    QListWidgetItem* cur=ui->TitleList->currentItem();
    int id=ui->TitleList->row(cur);
    delete ui->TitleList->takeItem(id);
    archive.append(list.at(id));
    list.removeAt(id);
}

void MainWindow::AllNotes(){
    QString choise[4]={"Робочі","Відпочинок","Персональні","Ідеї/Плани"};
    for(int i=0;i<4;i++)
    {
        QListWidgetItem* cur=new QListWidgetItem();
        cur->setText(choise[i]);
        ui->Screen->addItem(cur);
    }
}
void MainWindow::WriteTemp(QString text){
    QString filename="temp.txt";
        QFile file(filename);
       file.open(QIODevice::WriteOnly);
       QTextStream out(&file);
                out<<text<<Qt::endl;
      file.close();
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
        std::sort(list.begin(), list.end(), Note::compareFunction);
        for (auto begin = list.begin(); begin != list.end(); begin++)
        {
            if(id==begin->GetType())
            {
                QListWidgetItem *cur=new QListWidgetItem;
                cur->setText(begin->GetTitle());
                SCR->insertItem(0,cur);
            }
            else if(id==begin->GetTitle())
            {
               WriteTemp(begin->GetText());
               SCR->clear();
               AllNotes();
               OurText add;
                add.setModal(true);
                add.Show();
                add.exec();break;
            }
        }
    }

}
