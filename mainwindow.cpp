#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "startdialog.h"
/////////////2012-4-11 itemviews
#include "dommodel.h"
#include "mainwindow.h"
#include <QDomDocument>
#include <QFile>
#include <QtGui>
/////////////2012-4-11 itemviews

////2012-4-12 higlighter
#include "highlighter.h"
////2012-4-12 higlighter

#include <QTextBrowser>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   this->setWindowIcon(QIcon("a.png"));
    ui->setupUi(this);
    createActions();
    createMenus();
    createToolBars();
    stepEditor();
    cmd = new QProcess;
    connect(ui->startButton,SIGNAL(clicked()),this,SLOT(selectCard()));

    ////2012-4-12 add QProcess
    /*
    connect(ui->stopButton,SIGNAL(clicked()),this,SLOT(runProcess()));
    connect(cmd, SIGNAL(readyRead()), this, SLOT(readOutput()));
    */
    ////2012-4-12 add QProcess
    ////2012-4-11 itemviews
    model = new DomModel(QDomDocument(), this);
    ////2012-4-11 itemviews
    ////2012-4-16
    connect(cmd,SIGNAL(readyRead()),this,SLOT(writeToTextBrowser()));
    connect(ui->stopButton,SIGNAL(clicked()),this,SLOT(runProcess()));
    ////2012-4-16
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
////////////////////////////////////////////
void MainWindow::createActions()
{
    newAction = new QAction(tr("&New"),this);
    newAction->setIcon(QIcon(":/images/new.png"));
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(tr("New a new MessageBox..."));
//    connect(newAction,SIGNAL(triggered()),this,SLOT(newFile()));
    /////////////2012-4-11 itemviews
    connect(newAction,SIGNAL(triggered()),this,SLOT(openFile()));
    /////////////2012-4-11 itemviews

    openAction = new QAction(tr("&open"),this);
    openAction->setIcon(QIcon(":/images/open.png"));
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open a new MessageBox.."));
    connect(openAction,SIGNAL(triggered()),this,SLOT(selectCard()));

    saveAction = new QAction(tr("&Save"),this);
    saveAction->setIcon(QIcon(":/images/save.png"));
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save MessageBox.."));
    connect(saveAction,SIGNAL(triggered()),this,SLOT(about()));

    saveAsAction = new QAction(tr("Save &As"),this);
    saveAsAction->setIcon(QIcon(":/images/open.png"));
    saveAsAction->setShortcut(QKeySequence::SaveAs);
    saveAsAction->setStatusTip(tr("Save as MessageBox.."));
    connect(saveAsAction,SIGNAL(triggered()),this,SLOT(about()));

    copyAction = new QAction(tr("Copy"),this);
    copyAction->setIcon(QIcon(":/images/copy.png"));
    copyAction->setShortcut(QKeySequence::Copy);

    cutAction = new QAction(tr("Cut"),this);
    cutAction->setIcon(QIcon(":/images/cut.png"));
    cutAction->setShortcut(QKeySequence::Cut);

    pasteAction = new QAction(tr("Paste"),this);
    pasteAction->setIcon(QIcon(":/images/paste.png"));
    pasteAction->setShortcut(QKeySequence::Paste);

    findAction = new QAction(tr("Find"),this);
    findAction->setIcon(QIcon(":/images/find.png"));
    findAction->setShortcut(QKeySequence::Find);

    firstAction = new QAction(tr("First Packet"),this);
    firstAction->setIcon(QIcon(":/images/first.png"));

    endAction = new QAction(tr("End Packet"),this);
    endAction->setIcon(QIcon(":/images/end.png"));

    previousAction = new QAction(tr("Previous..."),this);
    previousAction->setIcon(QIcon(":/images/previous.png"));

    nextAction = new QAction(tr("Next..."),this);
    nextAction->setIcon(QIcon(":/images/next.png"));



    exitAction = new QAction(tr("&Exit"),this);
    exitAction->setShortcut(QKeySequence::Quit);
    exitAction->setStatusTip(tr("Exit This MainWindow.."));
    connect(exitAction,SIGNAL(triggered()),qApp,SLOT(aboutQt()));

    aboutAction = new QAction(tr("&About This"),this);
   // aboutAction->setIcon(QIcon(":/images/cut.png"));
   // aboutAction->setShortcut(QKeySequence::New);
    aboutAction->setStatusTip(tr("About actions.."));
    connect(aboutAction,SIGNAL(triggered()),this,SLOT(about()));

//    QAction *FAQAction;
    FAQAction = new QAction(tr("FAQ's"),this);
//    QAction *WebsiteAction;
    WebsiteAction = new QAction(tr("&Website"),this);
//    QAction *downloadAction;
    downloadAction = new QAction(tr("&Downloads"),this);
//    QAction *WiKiAction;
    WiKiAction = new QAction(tr("WiKi"),this);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    separatorAction = fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    editMenu = menuBar()->addMenu(tr("&Edit"));

    toolMenu = menuBar()->addMenu(tr("&Tools"));

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(FAQAction);
    helpMenu->addSeparator();//separator The menu..
    helpMenu->addAction(WebsiteAction);
    helpMenu->addAction(downloadAction);
    helpMenu->addAction(WiKiAction);
}


void MainWindow::createToolBars()
{
    fileToolBar = addToolBar(tr("&File"));
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(openAction);
    fileToolBar->addAction(saveAction);

    editToolBar = addToolBar(tr("&Edit"));
    editToolBar->addAction(copyAction);
    editToolBar->addAction(cutAction);
    editToolBar->addAction(pasteAction);
    editToolBar->addSeparator();
    editToolBar->addAction(firstAction);
    editToolBar->addAction(endAction);
    editToolBar->addAction(previousAction);
    editToolBar->addAction(nextAction);
}
bool MainWindow::okToContinue()
{
    if(isWindowModified()){
        int r = QMessageBox::warning(this,tr("Warning"),
                                     tr("The Document has been modified\n"
                                        "Do you want to save you changes"),
                                     QMessageBox::Yes|QMessageBox::No
                                     |QMessageBox::Cancel);
        if(r == QMessageBox::Yes){
            //.....
        }else if(r == QMessageBox::Cancel){
            //.....
        }
    }
    return true;
}


void MainWindow::about()
{
    QMessageBox::about(this,tr("About This Dialog"),
                       tr("<h2>Version1.0</h2>"
                          "<p>Copyright &copy;2011 Software Inc."
                          "<p>This is my First Dialog"
                          "<p>My first Menu..."));
}

void MainWindow::newFile()
{
    if(okToContinue()){
        about();
    }
}

void MainWindow::selectCard()
{
    startDialog dialog(this);
    dialog.exec();
    dev = dialog.devs;
    ui->cardLabel->setText(dev);
}

/////////////2012-4-11 itemviews
void MainWindow::openFile(){
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"),
             xmlPath, tr("XML files (*.xml);;HTML files (*.html);;"
                         "SVG files (*.svg);;User Interface files (*.ui)"));

         if (!filePath.isEmpty()) {
             QFile file(filePath);
             if (file.open(QIODevice::ReadOnly)) {
                 QDomDocument document;
                 if (document.setContent(&file)) {
                     DomModel *newModel = new DomModel(document, this);
                     ////2012-4-12 change the treeView to textBrowser
                     //ui->treeView->setModel(newModel);
                     ////2012-4-12 change the treeView to textBrowser
                     delete model;
                     model = newModel;
                     xmlPath = filePath;
                 }
                 file.close();
             }
         }
}
/////////////2012-4-11 itemviews

////2012-4-12 higlighter
void MainWindow::stepEditor(){
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(10);

    ui->textBrowser->setFont(font);

   // highlighter = new Highlighter(editor->document());
    highlighter = new Highlighter(ui->textBrowser->document());
}
////2012-4-12 higlighter

////2012-4-12 add QProcess
/*
void MainWindow::runProcess(){
    cmd = new QProcess;

    cmd->start("sniff");
    output = tr("");
    ui->textBrowser->setText(output);
   // outputEdit->setText(output);
}
void MainWindow::readOutput(){
    output += cmd->readAll();
    ui->textBrowser->setText(output);
    //outputEdit->setText(output);
}
*/
////2012-4-12 add QProcess

////2012-4-16
void MainWindow::writeToTextBrowser(){
    strData+=cmd->readAll();
    ui->textBrowser->append(strData);
}
void MainWindow::runProcess(){
//    QStringList arguments;
//         arguments << "-style" << "motif";
//
//         QProcess *myProcess = new QProcess(parent);
//         myProcess->start(program, arguments);
    QString program = "/bin/ls";
    QStringList arguments;
    QString countData;
    QString portData;
    countData = ui->numberLineEdit->text();
    portData = ui->portLineEdit->text();
    arguments<<"-"<<countData<<portData;
   // ui->textBrowser->append(countData+portData);
    cmd->start("./sniff");
    strData=tr("");
    ui->textBrowser->append(strData);
}
////2012-4-16
