/********************************************************************************
** Form generated from reading UI file 'startdialog.ui'
**
** Created: Wed Apr 11 14:18:05 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTDIALOG_H
#define UI_STARTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_startDialog
{
public:
    QPushButton *startButton;
    QPushButton *quitButton;
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *okButton;

    void setupUi(QDialog *startDialog)
    {
        if (startDialog->objectName().isEmpty())
            startDialog->setObjectName(QString::fromUtf8("startDialog"));
        startDialog->resize(400, 300);
        startButton = new QPushButton(startDialog);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(30, 220, 93, 27));
        quitButton = new QPushButton(startDialog);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(270, 220, 93, 27));
        label = new QLabel(startDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 80, 101, 61));
        comboBox = new QComboBox(startDialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(170, 90, 111, 41));
        okButton = new QPushButton(startDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(150, 220, 93, 27));

        retranslateUi(startDialog);
        QObject::connect(quitButton, SIGNAL(clicked()), startDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(startDialog);
    } // setupUi

    void retranslateUi(QDialog *startDialog)
    {
        startDialog->setWindowTitle(QApplication::translate("startDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        startButton->setText(QApplication::translate("startDialog", "&Start", 0, QApplication::UnicodeUTF8));
        quitButton->setText(QApplication::translate("startDialog", "&Quit", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("startDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600;\">ListCard:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("startDialog", "&OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class startDialog: public Ui_startDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTDIALOG_H
