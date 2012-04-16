#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <pcap.h>
#include "ui_startdialog.h"

class startDialog : public QDialog, public Ui_startDialog
{
    Q_OBJECT
public:
    startDialog(QWidget *parent = 0);
    ~startDialog();
    QString devs;

protected:
    void changeEvent(QEvent *e);

private:
    pcap_if_t *alldevs,*next,*d;
    char    errbuf[PCAP_ERRBUF_SIZE];
    bool ifSelectCard ;
private slots:
    void setDevice(int);
    void comboBoxChange();
};

#endif // STARTDIALOG_H
