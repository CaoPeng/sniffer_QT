#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMessageBox>
#include <QSplashScreen>
#include <QString>
#include <QtGui/QTextBrowser>
#include <pcap.h>
#include <QtGui/QTextBrowser>
/////////////2012-4-11 itemviews
class QMenu;
class QTreeView;
class DomModel;
/////////////2012-4-11 itemviews

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

private:
    QString dev;
    /////////////2012-4-11 itemviews
    DomModel *model;
    /////////////2012-4-11 itemviews

    Ui::MainWindow *ui;
    void createActions();
    void createMenus();
    void createToolBars();
    bool okToContinue();

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
