#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //Sets up first screen
    ui->setupUi(this);
    usrName = "";
    MainLogin* loginScreen = new MainLogin(this);
    loginScreen->setParent(this);
    loggedIn = false;
    setWindowTitle("Tic Tac Toe");
    setCentralWidget(loginScreen);
    enablerForMainLogin();
    //Connects the QActions to their appropriate actions
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionRegister_User, SIGNAL(triggered()), this, SLOT(actionRegister_User_triggered()));
    connect(ui->actionLogout_User, SIGNAL(triggered()), this, SLOT(actionLogout_User_triggered()));
    connect(ui->actionNew_Game, SIGNAL(triggered()), this, SLOT(actionNew_Game_triggered()));//Fix
    connect(ui->actionEnd_Game, SIGNAL(triggered()), this, SLOT(actionEnd_Game_triggered()));//Fix
    connect(ui->actionChange_Password, SIGNAL(triggered()), this, SLOT(actionChange_Password_triggered()));
}
void MainWindow::changePanel(QWidget* widget)
{
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::actionRegister_User_triggered()
{
    RegisterUser* registerScreen = new RegisterUser(this);
    enablerForRegisterUser();
    setCentralWidget(registerScreen);
    setWindowTitle("Register User");
}
void MainWindow::actionLogout_User_triggered()
{
    enablerForMainLogin();
    MainLogin* loginScreen = new MainLogin(this);
    loginScreen->setParent(this);
    setWindowTitle("Tic Tac Toe");
    setCentralWidget(loginScreen);
    loggedIn = false;
}
void MainWindow::actionNew_Game_triggered()
{
    enablerForGame();
    GameBoard* game = new GameBoard();
    game->setColor(color);
    game->setUserName(usrName);
    setWindowTitle("Game");
    setCentralWidget(game);
}

void MainWindow::actionEnd_Game_triggered()
{
    Welcome* welcomeScreen = new Welcome();
    welcomeScreen->setUserName(usrName);
    changePanel(welcomeScreen);
    setWindowTitle("Welcome");
    enablerForWelcome();
}
void MainWindow::actionChange_Password_triggered()
{
    NewPassword* newPwd = new NewPassword(this);
    setWindowTitle("New Password");
    setCentralWidget(newPwd);
    enablerForChangePassword();
}
void MainWindow::enablerForMainLogin()
{
    ui->actionRegister_User->setEnabled(true);
    ui->actionLogout_User->setDisabled(true);
    ui->actionNew_Game->setDisabled(true);
    ui->actionEnd_Game->setDisabled(true);
    ui->actionChange_Password->setDisabled(true);
    ui->actionExit->setEnabled(true);
}

void MainWindow::enablerForRegisterUser()
{
    ui->actionRegister_User->setDisabled(true);
    ui->actionLogout_User->setDisabled(true);
    ui->actionNew_Game->setDisabled(true);
    ui->actionEnd_Game->setDisabled(true);
    ui->actionChange_Password->setDisabled(true);
    ui->actionExit->setEnabled(true);
}

void MainWindow::enablerForWelcome()
{
    ui->actionRegister_User->setDisabled(true);
    ui->actionLogout_User->setEnabled(true);
    ui->actionNew_Game->setEnabled(true);
    ui->actionEnd_Game->setDisabled(true);
    ui->actionChange_Password->setEnabled(true);
    ui->actionExit->setEnabled(true);
}

void MainWindow::enablerForGame()
{
    ui->actionRegister_User->setDisabled(true);
    ui->actionLogout_User->setEnabled(true);
    ui->actionNew_Game->setDisabled(true);
    ui->actionEnd_Game->setEnabled(true);
    ui->actionChange_Password->setDisabled(true);
    ui->actionExit->setEnabled(true);
}

void MainWindow::enablerForChangePassword()
{
    ui->actionRegister_User->setDisabled(true);
    ui->actionLogout_User->setEnabled(true);
    ui->actionNew_Game->setDisabled(true);
    ui->actionEnd_Game->setDisabled(true);
    ui->actionChange_Password->setDisabled(true);
    ui->actionExit->setEnabled(true);
}
void MainWindow::setUserName(QString usr)
{
    usrName = usr;
}
void MainWindow::setColor(QString clor)
{
    color = clor;
}
QString MainWindow::getColor()
{
    return color;
}
