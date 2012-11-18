#include "welcome.h"
#include "ui_welcome.h"

Welcome::Welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
    usrName = "";
}
void Welcome::setWelcomeText()
{
    ui->WelcomeText->setText("Welcome, " + usrName + "!");
}
void Welcome::setUserName(QString user)
{
    usrName = user;
    setWelcomeText();
}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::on_ChgPass_clicked()
{
    NewPassword* newPwd = new NewPassword(this);
    newPwd->setUserName(usrName);
    MainWindow* temp = qobject_cast<MainWindow*>(parent());
    temp->changePanel(newPwd);
    temp->setWindowTitle("New Password");
    temp->setCentralWidget(newPwd);
    temp->enablerForChangePassword();
    temp = NULL;
    delete temp;
}

void Welcome::on_StartGame_clicked()
{
    GameBoard* game = new GameBoard();
    game->setUserName(usrName);
    MainWindow* temp = qobject_cast<MainWindow*>(parent());
    temp->changePanel(game);
    game->setColor(temp->getColor());
    temp->setWindowTitle("Game");
    temp->setCentralWidget(game);
    temp->enablerForGame();
}

void Welcome::on_Exit_clicked()
{
    MainWindow* temp = qobject_cast<MainWindow*>(parent());
    temp->close();
}
