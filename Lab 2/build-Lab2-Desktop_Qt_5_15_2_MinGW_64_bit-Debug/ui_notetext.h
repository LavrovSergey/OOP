/********************************************************************************
** Form generated from reading UI file 'notetext.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTETEXT_H
#define UI_NOTETEXT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NoteText
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;

    void setupUi(QDialog *NoteText)
    {
        if (NoteText->objectName().isEmpty())
            NoteText->setObjectName(QString::fromUtf8("NoteText"));
        NoteText->resize(400, 300);
        label = new QLabel(NoteText);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 251, 21));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);
        pushButton = new QPushButton(NoteText);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(270, 240, 93, 28));
        widget = new QWidget(NoteText);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 50, 381, 171));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);


        retranslateUi(NoteText);

        QMetaObject::connectSlotsByName(NoteText);
    } // setupUi

    void retranslateUi(QDialog *NoteText)
    {
        NoteText->setWindowTitle(QCoreApplication::translate("NoteText", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("NoteText", "Title of the note and note", nullptr));
        pushButton->setText(QCoreApplication::translate("NoteText", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NoteText: public Ui_NoteText {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTETEXT_H
