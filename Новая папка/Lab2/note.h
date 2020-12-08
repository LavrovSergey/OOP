#ifndef NOTE_H
#define NOTE_H
#include <QString>
#include <QDateTime>
class Note
{
protected:
    QString Title;
    QString Text;
    QDateTime Date;
    QString type;
public:
    Note(QString Text,QString Title, QString type);
    QString GetTitle();
     QString GetText();
      QDateTime GetDate();
      QString GetType();
      void ToFile();
      static bool compareFunction( Note &n1,  Note &n2);
};

#endif // NOTE_H
