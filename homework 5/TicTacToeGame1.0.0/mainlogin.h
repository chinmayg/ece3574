#ifndef MAINLOGIN_H
#define MAINLOGIN_H

#include <QWidget>
#include <QDebug>
#include <QFile>
#include <QDataStream>
#include <QByteArray>
#include <QCryptographicHash>
#include <QMessageBox>
#include "welcome.h"
#include "mainwindow.h"


struct MemberData {
    QString name;
    QString color;
    QByteArray passwordDigest;
};

QDataStream &operator>>(QDataStream &in, MemberData &m);

namespace Ui {
class MainLogin;
}

class MainLogin : public QWidget
{
    Q_OBJECT
    
public:
    explicit MainLogin(QWidget *parent = 0);
    ~MainLogin();

private slots:
    void on_Login_clicked();

    void on_Exit_clicked();

private:
    Ui::MainLogin *ui;
};

#endif // MAINLOGIN_H
