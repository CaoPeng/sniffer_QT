#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "startdialog.h"
#include "mainwindow.h"
#include <QFile>
#include <QtGui>
#include <QTextCursor>
////2012-4-12 higlighter
#include "highlighter.h"
////2012-4-12 higlighter


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    isSaved = false;
    curFile = "untitled";
    ui->setupUi(this);
    createActions();
    createMenus();
    createToolBars();
    stepEditor();
    cmd = new QProcess;
    connect(ui->selectCardButton,SIGNAL(clicked()),this,SLOT(selectCard()));


    ////2012-4-16 QProcess
    connect(cmd,SIGNAL(readyRead()),this,SLOT(writeToTextBrowser()));
    connect(ui->startButton,SIGNAL(clicked()),this,SLOT(runProcess()));
    ////2012-4-16 QProcess
    connect(ui->stopButton,SIGNAL(clicked()),cmd,SLOT(kill()));

    connect(ui->comboBoxPort,SIGNAL(currentIndexChanged(int)),this,SLOT(getcomboBoxPort(int)));
    connect(ui->comboBoxFilter,SIGNAL(currentIndexChanged(int)),this,SLOT(getcomboBoxFilter(int)));

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
    connect(newAction,SIGNAL(triggered()),this,SLOT(newFile()));

    openAction = new QAction(tr("&open"),this);
    openAction->setIcon(QIcon(":/images/open.png"));
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open a new MessageBox.."));
    connect(openAction,SIGNAL(triggered()),this,SLOT(openFiles()));

    saveAction = new QAction(tr("&Save"),this);
    saveAction->setIcon(QIcon(":/images/save.png"));
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save MessageBox.."));
    connect(saveAction,SIGNAL(triggered()),this,SLOT(doSaveFiles()));

    saveAsAction = new QAction(tr("Save &As"),this);
    saveAsAction->setIcon(QIcon(":/images/open.png"));
    saveAsAction->setShortcut(QKeySequence::SaveAs);
    saveAsAction->setStatusTip(tr("Save as MessageBox.."));
    connect(saveAsAction,SIGNAL(triggered()),this,SLOT(saveAsFiles()));

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
    ////2012-4-25
    connect(findAction,SIGNAL(triggered()),this,SLOT(findText()));
    ////2012-4-25

    aboutQTAction = new QAction(tr("&About QT"),this);
    aboutQTAction->setStatusTip(tr("About QT program.."));
    connect(aboutQTAction,SIGNAL(triggered()),qApp,SLOT(aboutQt()));

    exitAction = new QAction(tr("&Exit"),this);
    exitAction->setShortcut(QKeySequence::Quit);
    exitAction->setStatusTip(tr("Exit This MainWindow.."));
    connect(exitAction,SIGNAL(triggered()),qApp,SLOT(quit()));

    aboutAction = new QAction(tr("&About This"),this);
    aboutAction->setStatusTip(tr("Help Document"));
    connect(aboutAction,SIGNAL(triggered()),this,SLOT(help()));

//    FAQAction = new QAction(tr("FAQ's"),this);
//    downloadAction = new QAction(tr("&Downloads"),this);
//    WiKiAction = new QAction(tr("WiKi"),this);
}

void MainWindow::createMenus(){
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    separatorAction = fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQTAction);
//    helpMenu->addAction(FAQAction);
//    helpMenu->addSeparator();//separator The menu..
//    helpMenu->addAction(downloadAction);
//    helpMenu->addAction(WiKiAction);
}

void MainWindow::createToolBars(){
    fileToolBar = addToolBar(tr("&File"));
    fileToolBar->addAction(newAction);

    fileToolBar->addAction(findAction);
    fileToolBar->addAction(saveAction);

    editToolBar = addToolBar(tr("&Edit"));
    editToolBar->addAction(copyAction);
    editToolBar->addAction(cutAction);
    editToolBar->addAction(pasteAction);
}
void MainWindow::newFile()
{
    if(!isWindowModified()){
        int r = QMessageBox::warning(this,tr("Warning"),
                                     tr("The Document has been modified\n"
                                        "Do you want to save you changes"),
                                     QMessageBox::Yes|QMessageBox::No);
        if(r == QMessageBox::Yes){
            doSaveFiles();
        }
    }
    ui->textBrowser->clear();
}

void MainWindow::about()
{
    QMessageBox::about(this,tr("About This Dialog"),
                       tr("<h2>Version1.0</h2>"
                          "<p>Copyright &copy;2011 Software Inc."
                          "<p>This is my First Dialog"
                          "<p>My first Menu..."));
}

void MainWindow::selectCard()
{
    startDialog dialog(this);
    dialog.exec();
    dev = dialog.devs;
    ui->cardLabel->setText(dev);
    ui->cardLabel->setCursor(Qt::SizeAllCursor);
}

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

////2012-4-16
void MainWindow::writeToTextBrowser(){
    strData+=cmd->readAll();
    ui->textBrowser->append(strData);
}
void MainWindow::runProcess(){
    QString countData;
    QString argvExe = "./sniff";
    QString argvK = " -k ";
    QString argvN = " -n ";
    QString argvF = " -f ";
    QString argvD = " -d ";
    countData = ui->numberLineEdit->text();
    QString myexe = argvExe+argvK+port+argvN+countData+argvF+filter;
    cmd->start(myexe);
    strData=tr("");
    ui->textBrowser->append(strData);
}
////2012-4-16

////2012-4-25 findText
void MainWindow::findText(){
    QDialog *findDlg = new QDialog(this);
    //新建一个对话框，用于查找操作，this表明它的父窗口是MainWindow。
    findDlg->setWindowTitle(tr("Find"));

    QLabel *findLabel = new QLabel(tr("Find:"));
    find_textLineEdit = new QLineEdit(findDlg);
    QPushButton *find_Btn_Next = new QPushButton(tr("Next"),findDlg);
    find_Btn_Next->setIcon(QIcon(":/images/next.png"));
    QPushButton *find_Btn_Previous = new QPushButton(tr("Previous"),findDlg);
    find_Btn_Previous->setIcon(QIcon(":/images/previous.png"));
    //加入一个“查找下一个”的按钮
    QHBoxLayout* layout = new QHBoxLayout(findDlg);
    layout->addWidget(findLabel);
    layout->addWidget(find_textLineEdit);
    layout->addWidget(find_Btn_Previous);
    layout->addWidget(find_Btn_Next);
    //新建一个垂直布局管理器，并将行编辑器和按钮加入其中
    findDlg ->show();
    connect(find_Btn_Previous,SIGNAL(clicked()),this,SLOT(findTextNext()));
    connect(find_Btn_Next,SIGNAL(clicked()),this,SLOT(findTextPrevious()));
    //显示对话框
}
void MainWindow::findTextNext(){
    QString findStr = find_textLineEdit->text();
    if(!ui->textBrowser->find(findStr,QTextDocument::FindBackward)){
        QMessageBox::warning(this,tr("Find"),tr("No Find %1")
                             .arg(findStr));
    }
}
void MainWindow::findTextPrevious(){
    QString findStr = find_textLineEdit->text();
    if(!ui->textBrowser->find(findStr/*,QTextDocument::FindBackward*/)){
        QMessageBox::warning(this,tr("Find"),tr("No Find %1")
                             .arg(findStr));
    }
}
////2012-4-25 findText
////2012-5-03 save files
void MainWindow::openFiles(){
    doFileSaveOrNot();
    QString fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty()){
        loadFile(fileName);
    }
}
void MainWindow::doSaveFiles(){
    if(isSaved){
        saveFile(curFile);
    }else{
        saveAsFiles();
    }
}
void MainWindow::saveAsFiles(){
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save As.."),curFile);
    if(!fileName.isEmpty()){
        saveFile(fileName);
    }
}
////2012-5-03 save files
////2012-5-4 save files version 2.0
void MainWindow::doFileSaveOrNot(){
    if(ui->textBrowser->document()->isModified()){
        QMessageBox box;
        box.setWindowTitle(tr("Warning"));
        box.setIcon(QMessageBox::Warning);
        box.setText(curFile+tr("Does not saved. saved?"));
        box.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
        if(box.exec() == QMessageBox::Yes){
            doSaveFiles();
        }//if == QMessageBox::Yes
    }//if   isModified();
}
void MainWindow::saveFile(const QString &fileName){
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly|QFile::Text)){
        QMessageBox::warning(this,
                             tr("save files.."),
                             tr("Not save %s :\n %2")
                             .arg(fileName)
                             .arg(file.errorString()));
    }
    QTextStream out(&file);
    out<<ui->textBrowser->toPlainText();
    isSaved = true;
    curFile = QFileInfo(fileName).canonicalFilePath();
    setWindowTitle(curFile);
}
void MainWindow::loadFile(const QString &fileName){
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly|QFile::Text)){
        QMessageBox::warning(this,
                             tr("read files"),
                             tr("Not read file %1 :\n %2")
                             .arg(fileName)
                             .arg(file.errorString()));
    }
    QTextStream in(&file);
    ui->textBrowser->setText(in.readAll());
    curFile = QFileInfo(fileName).canonicalFilePath();
    setWindowTitle(curFile);
}
////2012-5-4 save files version 2.0
////2012-5-05 help files
void MainWindow::help(){
    HelpBrowser::showPage("index.html");
}
////2012-5-05 help files
void MainWindow::getcomboBoxFilter(int filterCount){
    filter = ui->comboBoxFilter->itemText(filterCount);
}
void MainWindow::getcomboBoxPort(int portCount){
    port = ui->comboBoxPort->itemText(portCount);
}
