#include "note.h"
#include<QFile>
#include <QTextStream>
Note::Note(QString Title,QString Text, QString type)
{
    this->type=type;
    this->Text=Text;
    this->Title=Title;
    this->Date=QDateTime::currentDateTime();
}
QString Note::GetTitle(){return Title;}
 QString Note::GetText(){return Text;}
  QDateTime Note::GetDate(){return Date;}
  QString Note::GetType(){return type;}
  bool Note::compareFunction( Note &n1,  Note &n2){
      return n1.GetDate()<n2.GetDate();
  }
