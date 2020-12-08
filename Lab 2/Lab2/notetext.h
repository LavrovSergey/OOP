#ifndef NOTETEXT_H
#define NOTETEXT_H

#include <QDialog>

namespace Ui {
class NoteText;
}

class NoteText : public QDialog
{
    Q_OBJECT

public:
    explicit NoteText(QWidget *parent = nullptr);
    ~NoteText();

private:
    Ui::NoteText *ui;
};

#endif // NOTETEXT_H
