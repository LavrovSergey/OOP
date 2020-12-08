#include "notetext.h"
#include "ui_notetext.h"

NoteText::NoteText(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NoteText)
{
    ui->setupUi(this);
}

NoteText::~NoteText()
{
    delete ui;
}

void NoteText::on_pushButton_clicked()
{
   MainWindow:: Add1();
}
