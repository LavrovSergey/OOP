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
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_NoteText
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *NoteText)
    {
        if (NoteText->objectName().isEmpty())
            NoteText->setObjectName(QString::fromUtf8("NoteText"));
        NoteText->resize(400, 300);
        buttonBox = new QDialogButtonBox(NoteText);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(NoteText);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 341, 201));

        retranslateUi(NoteText);
        QObject::connect(buttonBox, SIGNAL(accepted()), NoteText, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NoteText, SLOT(reject()));

        QMetaObject::connectSlotsByName(NoteText);
    } // setupUi

    void retranslateUi(QDialog *NoteText)
    {
        NoteText->setWindowTitle(QCoreApplication::translate("NoteText", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("NoteText", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NoteText: public Ui_NoteText {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTETEXT_H
