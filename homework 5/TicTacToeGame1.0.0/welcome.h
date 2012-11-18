#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include <QDebug>
#include "newpassword.h"
#include "mainwindow.h"
#include "gameboard.h"

namespace Ui {
class Welcome;
}

class Welcome : public QWidget
{
    Q_OBJECT
    
public:
    explicit Welcome(QWidget *parent = 0);
    void setUserName(QString user);
    ~Welcome();
    
private slots:
    void on_ChgPass_clicked();

    void on_StartGame_clicked();

    void on_Exit_clicked();

private:
    Ui::Welcome *ui;
    QString usrName;
    void setWelcomeText();
};

#endif // WELCOME_H
