#include "startdialog.h"
#include "ui_startdialog.h"

startDialog::startDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    ifSelectCard = false;
    devs = "eth0";
    connect(startButton,SIGNAL(clicked()),this,SLOT(comboBoxChange()));
    connect(comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(setDevice(int)));
}

startDialog::~startDialog()
{
    //delete ui;
}

void startDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
      //  ui->retranslateUi(this);
        retranslateUi(this);
        break;
    default:
        break;
    }
}
void startDialog::setDevice(int index)
{
    devs = comboBox->itemText(index);
}
void startDialog::comboBoxChange()
{
    int i=0;

    if(ifSelectCard == true){
        comboBox->clear();
    }
    if(pcap_findalldevs(&alldevs,errbuf) == 1){
         QMessageBox msgBox;
         msgBox.setText("The document has been modified.");
         msgBox.exec();
    }

    for( d = alldevs;d ; d = d->next){
        comboBox->insertItems(i,
                              QStringList()<<QApplication::translate("Dialog",
                                            d->name,
                                            0,
                                            QApplication::UnicodeUTF8));
        i++;
    }
    ifSelectCard = true;
}
