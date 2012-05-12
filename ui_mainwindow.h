/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon May 7 14:33:03 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *cardLabel;
    QPushButton *selectCardButton;
    QLabel *numberLabel;
    QLineEdit *numberLineEdit;
    QLabel *portLabel;
    QLineEdit *portLineEdit;
    QLabel *labelFilter;
    QLineEdit *filterLineEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *stopButton;
    QPushButton *startButton;
    QTextBrowser *textBrowser;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1030, 633);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cardLabel = new QLabel(centralWidget);
        cardLabel->setObjectName(QString::fromUtf8("cardLabel"));
        cardLabel->setTextFormat(Qt::AutoText);
        cardLabel->setScaledContents(false);

        horizontalLayout->addWidget(cardLabel);

        selectCardButton = new QPushButton(centralWidget);
        selectCardButton->setObjectName(QString::fromUtf8("selectCardButton"));

        horizontalLayout->addWidget(selectCardButton);

        numberLabel = new QLabel(centralWidget);
        numberLabel->setObjectName(QString::fromUtf8("numberLabel"));

        horizontalLayout->addWidget(numberLabel);

        numberLineEdit = new QLineEdit(centralWidget);
        numberLineEdit->setObjectName(QString::fromUtf8("numberLineEdit"));

        horizontalLayout->addWidget(numberLineEdit);

        portLabel = new QLabel(centralWidget);
        portLabel->setObjectName(QString::fromUtf8("portLabel"));

        horizontalLayout->addWidget(portLabel);

        portLineEdit = new QLineEdit(centralWidget);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));

        horizontalLayout->addWidget(portLineEdit);

        labelFilter = new QLabel(centralWidget);
        labelFilter->setObjectName(QString::fromUtf8("labelFilter"));

        horizontalLayout->addWidget(labelFilter);

        filterLineEdit = new QLineEdit(centralWidget);
        filterLineEdit->setObjectName(QString::fromUtf8("filterLineEdit"));

        horizontalLayout->addWidget(filterLineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));

        horizontalLayout->addWidget(stopButton);

        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        horizontalLayout->addWidget(startButton);


        verticalLayout->addLayout(horizontalLayout);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1030, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        cardLabel->setText(QApplication::translate("MainWindow", "eth0:", 0, QApplication::UnicodeUTF8));
        selectCardButton->setText(QApplication::translate("MainWindow", "&\345\274\200\345\247\213", 0, QApplication::UnicodeUTF8));
        numberLabel->setText(QApplication::translate("MainWindow", "\344\270\252\346\225\260:", 0, QApplication::UnicodeUTF8));
        portLabel->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243:", 0, QApplication::UnicodeUTF8));
        labelFilter->setText(QApplication::translate("MainWindow", "\350\277\207\346\273\244:", 0, QApplication::UnicodeUTF8));
        stopButton->setText(QApplication::translate("MainWindow", "&Stop", 0, QApplication::UnicodeUTF8));
        startButton->setText(QApplication::translate("MainWindow", "&Start", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
