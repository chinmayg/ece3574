#ifndef NEWPASSWORD_H
#define NEWPASSWORD_H

#include <QWidget>
#include <QMessageBox>
#include "welcome.h"
#include "mainwindow.h"

struct NewPasswordData {
    QString name;
    QString color;
    QByteArray passwordDigest;
};

QDataStream &operator>>(QDataStream &in, NewPasswordData &m);
QDataStream &operator<<(QDataStream &out, const NewPasswordData &m);

namespace Ui {
class NewPassword;
}

class NewPassword : public QWidget
{
    Q_OBJECT
    
public:
    explicit NewPassword(QWidget *parent = 0);
    void setUserName(QString text);
    ~NewPassword();
    
private slots:
    void on_ok_clicked();

    void on_cancel_clicked();

private:
    Ui::NewPassword *ui;
    QString usrName;
};

#endif // NEWPASSWORD_H
