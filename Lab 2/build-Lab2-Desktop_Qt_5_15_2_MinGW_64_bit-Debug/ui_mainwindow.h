/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *AddNote;
    QListWidget *TitleList;
    QPushButton *Archive;
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *NoteTitle;
    QPlainTextEdit *NoteText;
    QListWidget *Screen;
    QPushButton *Show;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *R1;
    QRadioButton *R2;
    QRadioButton *R3;
    QRadioButton *R4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 591);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        AddNote = new QPushButton(centralwidget);
        AddNote->setObjectName(QString::fromUtf8("AddNote"));
        AddNote->setGeometry(QRect(40, 230, 93, 28));
        AddNote->setCursor(QCursor(Qt::OpenHandCursor));
        TitleList = new QListWidget(centralwidget);
        TitleList->setObjectName(QString::fromUtf8("TitleList"));
        TitleList->setGeometry(QRect(40, 270, 341, 191));
        Archive = new QPushButton(centralwidget);
        Archive->setObjectName(QString::fromUtf8("Archive"));
        Archive->setGeometry(QRect(40, 470, 93, 28));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 10, 201, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Sitka Heading"));
        font.setPointSize(13);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label->setFont(font);
        label->setTextFormat(Qt::MarkdownText);
        label->setScaledContents(false);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 50, 701, 147));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        NoteTitle = new QLineEdit(layoutWidget);
        NoteTitle->setObjectName(QString::fromUtf8("NoteTitle"));

        verticalLayout->addWidget(NoteTitle);

        NoteText = new QPlainTextEdit(layoutWidget);
        NoteText->setObjectName(QString::fromUtf8("NoteText"));

        verticalLayout->addWidget(NoteText);

        Screen = new QListWidget(centralwidget);
        Screen->setObjectName(QString::fromUtf8("Screen"));
        Screen->setGeometry(QRect(420, 270, 351, 192));
        Show = new QPushButton(centralwidget);
        Show->setObjectName(QString::fromUtf8("Show"));
        Show->setGeometry(QRect(420, 470, 93, 28));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 200, 403, 22));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        R1 = new QRadioButton(widget);
        R1->setObjectName(QString::fromUtf8("R1"));

        horizontalLayout_3->addWidget(R1);

        R2 = new QRadioButton(widget);
        R2->setObjectName(QString::fromUtf8("R2"));

        horizontalLayout_3->addWidget(R2);

        R3 = new QRadioButton(widget);
        R3->setObjectName(QString::fromUtf8("R3"));

        horizontalLayout_3->addWidget(R3);

        R4 = new QRadioButton(widget);
        R4->setObjectName(QString::fromUtf8("R4"));

        horizontalLayout_3->addWidget(R4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        AddNote->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\264\320\260\321\202\320\270", nullptr));
        Archive->setText(QCoreApplication::translate("MainWindow", "\320\220\321\200\321\205\321\226\320\262\321\203\320\262\320\260\321\202\320\270", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Enter title of note", nullptr));
        NoteTitle->setText(QString());
        Show->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\270\320\262\320\270\321\202\320\270\321\201\321\217", nullptr));
        R1->setText(QCoreApplication::translate("MainWindow", "\320\240\320\276\320\261\320\276\321\207\321\226", nullptr));
        R2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\226\320\264\320\277\320\276\321\207\320\270\320\275\320\276\320\272", nullptr));
        R3->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\321\201\320\276\320\275\320\260\320\273\321\214\320\275\321\226", nullptr));
        R4->setText(QCoreApplication::translate("MainWindow", "\320\206\320\264\320\265\321\227/\320\237\320\273\320\260\320\275\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
