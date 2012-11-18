#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "mainlogin.h"
#include "registeruser.h"
#include "newpassword.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void changePanel(QWidget*);
    void enablerForMainLogin();
    void enablerForRegisterUser();
    void enablerForWelcome();
    void enablerForGame();
    void enablerForChangePassword();
    void setUserName(QString usr);
    void setColor(QString clor);
    QString getColor();
private slots:
    void actionRegister_User_triggered();
    void actionLogout_User_triggered();
    void actionNew_Game_triggered();
    void actionEnd_Game_triggered();
    void actionChange_Password_triggered();
private:
    Ui::MainWindow *ui;
    bool loggedIn;
    QString usrName;
    QString color;
};

#endif // MAINWINDOW_H
