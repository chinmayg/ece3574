#ifndef REGISTERUSER_H
#define REGISTERUSER_H

#include <QWidget>
#include <QDebug>
#include "mainwindow.h"
#include "mainlogin.h"

struct RegisterData {
    QString name;
    QString color;
    QByteArray passwordDigest;
};

QDataStream &operator>>(QDataStream &in, RegisterData &m);
QDataStream &operator<<(QDataStream &out, const RegisterData &m);

namespace Ui {
class RegisterUser;
}

class RegisterUser : public QWidget
{
    Q_OBJECT
    
public:
    explicit RegisterUser(QWidget *parent = 0);
    ~RegisterUser();
    
private slots:
    void on_Ok_clicked();

    void on_Cancel_clicked();

private:
    Ui::RegisterUser *ui;
};

#endif // REGISTERUSER_H
