#ifndef HELPBROWSER_H
#define HELPBROWSER_H

#include <QWidget>
#include <QString>
#include <QtGui/QTextBrowser>
#include <QtGui/QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDir>
#include <QtGui/QApplication>

class HelpBrowser : public QWidget
{
    Q_OBJECT
public:
    HelpBrowser(const QString &path,
                const QString &page,
                QWidget *parent=0);
    static void showPage(const QString &page);
    static QDir directoryOf(const QString &subdir);
private slots:
    void updateWindowTitle();
private:
    QTextBrowser *textBrowser;
    QPushButton *homeButton;
    QPushButton *backButton;
    QPushButton *closeButton;
};

#endif // HELPBROWSER_H
