#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMessageBox>
#include <QSplashScreen>
#include <QString>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextBrowser>

////2012-4-12 higlighter
class Highlighter;
////2012-4-12 add QProcess
class QProcess;
////2012-4-12 add QProcess
class QLineEdit;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static QString str;
    QString strcontext;
protected:
    void changeEvent(QEvent *e);

private slots:
    void newFile();
    void selectCard();
    void about();
    ////2012-4-16
    void writeToTextBrowser();
    void runProcess();
    ////2012-4-16
    ////2012-4-25 findText
    void findText();
    void findTextNext();
    ////2012-4-25 findText

private:
    QString dev;
    ////2012-4-12 higlighter
    Highlighter *highlighter;
    ////2012-4-12 higlighter
    ////2012-4-25 findText
    QLineEdit *find_textLineEdit;
    ////2012-4-25 findText

    ////2012-4-16
    QProcess *cmd;
    QString strData;
    ////2012-4-16

    Ui::MainWindow *ui;
    void createActions();
    void createMenus();
    void createToolBars();
    bool okToContinue();
    ////2012-4-12 higlighter
    void stepEditor();
    ////2012-4-12 higlighter

    //Menu
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *toolMenu;
    QMenu *helpMenu;
    //Actions
    QAction *separatorAction;
    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *exitAction;
    QAction *copyAction;
    QAction *cutAction;
    QAction *pasteAction;
    QAction *findAction;
    QAction *firstAction;
    QAction *endAction;
    QAction *nextAction;
    QAction *previousAction;

    //helpMenu
    QAction *aboutAction;
    QAction *FAQAction;
    QAction *WebsiteAction;
    QAction *downloadAction;
    QAction *WiKiAction;
    //QToolBar
    QToolBar *fileToolBar;
    QToolBar *editToolBar;
};

#endif // MAINWINDOW_H
