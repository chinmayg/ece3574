#include "gameboard.h"
#include <QPalette>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_gameboard.h"

GameBoard::GameBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameBoard)
{
    ui->setupUi(this);
    usrName = "";
    gameBoard = new QStringList();
    for(int i = 0; i < 9; i++){
        gameBoard->append("z");
    }
    uCount = 0;
    cCount = 0;
    dCount = 0;
}

void GameBoard::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    // Set color and width to the painter
    painter.drawLine(95,10,95,300); // vertical 1
    painter.drawLine(200,10,200,300); // vertical 2
    painter.drawLine(10,95,300,95);// horizontal 1
    painter.drawLine(10,200,300,200);// horizontal 2
}

void GameBoard::setUserName(QString user)
{
    usrName = user;
    ui->User->setText(user);
}

void GameBoard::setColor(QString colr)
{
    this->color = colr;
}

bool GameBoard::checkLocation(int x)
{
    if(gameBoard->at(x) == ("x") || gameBoard->at(x) == "o")
    {
        return true;
    }
    return false;
}
bool GameBoard::isAllFinished()
{
    bool isFull = true;
    for(int i = 0; i < 9; i++){
        if(gameBoard->at(i) == ("z"))
        {
            isFull = false;
        }
    }
    return isFull;
}

bool GameBoard::checkWin()
{
    bool playerWon = false;
    bool cpuWon = false;
    bool drawn = false;
    QMessageBox msgBox;
    if(gameBoard->at(0) == gameBoard->at(1) && gameBoard->at(1) == gameBoard->at(2)){
        if(gameBoard->at(0) == "x" && gameBoard->at(1) == "x" && gameBoard->at(2) == "x"){
            playerWon = true;
        }
        else if(gameBoard->at(0) == "o" && gameBoard->at(1) == "o" && gameBoard->at(2) == "o"){
            cpuWon = true;
        }
    }
    else if(gameBoard->at(3) == gameBoard->at(4) && gameBoard->at(4) == gameBoard->at(5)){
        if(gameBoard->at(3) == "x" && gameBoard->at(4) == "x" && gameBoard->at(5) == "x"){
            playerWon = true;
        }
        else if(gameBoard->at(3) == "o" && gameBoard->at(4) == "o" && gameBoard->at(5) == "o"){
            cpuWon = true;
        }
    }
    else if(gameBoard->at(6) == gameBoard->at(7) && gameBoard->at(7) == gameBoard->at(8)){
        if(gameBoard->at(6) == "x" && gameBoard->at(7) == "x" && gameBoard->at(8) == "x"){
            playerWon = true;
        }
        else if(gameBoard->at(6) == "o" && gameBoard->at(7) == "o" && gameBoard->at(8) == "o"){
            cpuWon = true;
        }
    }
    else if(gameBoard->at(0) == gameBoard->at(4) && gameBoard->at(4) == gameBoard->at(8)){
        if(gameBoard->at(0) == "x" && gameBoard->at(4) == "x" && gameBoard->at(8) == "x"){
            playerWon = true;
        }
        else if(gameBoard->at(0) == "o" && gameBoard->at(4) == "o" && gameBoard->at(8) == "o"){
            cpuWon = true;
        }
    }
    else if(gameBoard->at(6) == gameBoard->at(4) && gameBoard->at(4) == gameBoard->at(2)){
        if(gameBoard->at(6) == "x" && gameBoard->at(4) == "x" && gameBoard->at(2) == "x"){
            playerWon = true;
        }
        else if(gameBoard->at(6) == "o" && gameBoard->at(4) == "o" && gameBoard->at(2) == "o"){
            cpuWon = true;
        }
    }
    else if(gameBoard->at(0) == gameBoard->at(3) && gameBoard->at(3) == gameBoard->at(6)){
        if(gameBoard->at(0) == "x" && gameBoard->at(3) == "x" && gameBoard->at(6) == "x"){
            playerWon = true;
        }
        else if(gameBoard->at(0) == "o" && gameBoard->at(3) == "o" && gameBoard->at(6) == "o"){
            cpuWon = true;
        }
    }
    else if(gameBoard->at(1) == gameBoard->at(4) && gameBoard->at(4) == gameBoard->at(7)){
        if(gameBoard->at(1) == "x" && gameBoard->at(4) == "x" && gameBoard->at(7) == "x"){
            playerWon = true;
        }
        else if(gameBoard->at(1) == "o" && gameBoard->at(4) == "o" && gameBoard->at(7) == "o"){
            cpuWon = true;
        }
    }
    else if(gameBoard->at(2) == gameBoard->at(5) && gameBoard->at(5) == gameBoard->at(8)){
        if(gameBoard->at(2) == "x" && gameBoard->at(5) == "x" && gameBoard->at(8) == "x"){
            playerWon = true;
        }
        else if(gameBoard->at(2) == "o" && gameBoard->at(5) == "o" && gameBoard->at(8) == "o"){
            cpuWon = true;
        }
    }
    if(isAllFinished()){
        drawn = true;
    }
    MainWindow* temp = qobject_cast<MainWindow*>(parent());
    temp = NULL;
    delete temp;
    if(playerWon){
        msgBox.setText("The Player Won!");
        msgBox.setWindowTitle("");
        msgBox.setModal(true);
        msgBox.exec();
        resetBoard();
        uCount++;
        ui->CPULine->setText(QString::number(uCount));
        return true;
    }
    else if(cpuWon){
        msgBox.setText("The Computer Won!");
        msgBox.setWindowTitle("");
        msgBox.setModal(true);
        msgBox.exec();
        resetBoard();
        cCount++;
        ui->UserLine->setText(QString::number(cCount));
        return true;
    }
    else if(drawn){
        msgBox.setText("Draw Game");
        msgBox.setWindowTitle("");
        msgBox.setModal(true);
        msgBox.exec();
        resetBoard();
        dCount++;
        ui->DrawLine->setText(QString::number(dCount));
        return true;
    }
    return false;
}

QString GameBoard::getUserName()
{
    return usrName;
}

GameBoard::~GameBoard()
{
    delete ui;
}

void GameBoard::on_TL_clicked()
{
    if(!checkLocation(0)){
        gameBoard->replace(0,"x");
        if(color == "Blue"){
            ui->TL->setStyleSheet("color : blue");
        }
        else if(color == "Red"){
            ui->TL->setStyleSheet("color : red");
        }
        else if(color == "Green"){
            ui->TL->setStyleSheet("color : green");
        }
        ui->TL->setText("X");
        if(!checkWin()){
            computerMove();
        }
    }
}

void GameBoard::on_TC_clicked()
{
    if(!checkLocation(1)){
        gameBoard->replace(1,"x");
        if(color == "Blue"){
            ui->TC->setStyleSheet("color : blue");
        }
        else if(color == "Red"){
            ui->TC->setStyleSheet("color : red");
        }
        else if(color == "Green"){
            ui->TC->setStyleSheet("color : green");
        }
        ui->TC->setText("X");
        if(!checkWin()){
            computerMove();
        }
    }
}

void GameBoard::on_TR_clicked()
{
    if(!checkLocation(2)){
        gameBoard->replace(2,"x");
        if(color == "Blue"){
            ui->TR->setStyleSheet("color : blue");
        }
        else if(color == "Red"){
            ui->TR->setStyleSheet("color : red");
        }
        else if(color == "Green"){
            ui->TR->setStyleSheet("color : green");
        }
        ui->TR->setText("X");
        if(!checkWin()){
            computerMove();
        }
    }
}

void GameBoard::on_CL_clicked()
{
    if(!checkLocation(3)){
        gameBoard->replace(3,"x");
        if(color == "Blue"){
            ui->CL->setStyleSheet("color : blue");
        }
        else if(color == "Red"){
            ui->CL->setStyleSheet("color : red");
        }
        else if(color == "Green"){
            ui->CL->setStyleSheet("color : green");
        }
        ui->CL->setText("X");
        if(!checkWin()){
            computerMove();
        }
    }
}

void GameBoard::on_CC_clicked()
{
    if(!checkLocation(4)){
        gameBoard->replace(4,"x");
        if(color == "Blue"){
            ui->CC->setStyleSheet("color : blue");
        }
        else if(color == "Red"){
            ui->CC->setStyleSheet("color : red");
        }
        else if(color == "Green"){
            ui->CC->setStyleSheet("color : green");
        }
        ui->CC->setText("X");
        if(!checkWin()){
            computerMove();
        }
    }
}

void GameBoard::on_CR_clicked()
{
    if(!checkLocation(5)){
        gameBoard->replace(5,"x");
        if(color == "Blue"){
            ui->CR->setStyleSheet("color : blue");
        }
        else if(color == "Red"){
            ui->CR->setStyleSheet("color : red");
        }
        else if(color == "Green"){
            ui->CR->setStyleSheet("color : green");
        }
        if(!checkWin()){
            computerMove();
        }
    }
}

void GameBoard::on_BL_clicked()
{
    if(!checkLocation(6)){
        gameBoard->replace(6,"x");
        if(color == "Blue"){
            ui->BL->setStyleSheet("color : blue");
        }
        else if(color == "Red"){
            ui->BL->setStyleSheet("color : red");
        }
        else if(color == "Green"){
            ui->BL->setStyleSheet("color : green");
        }
        ui->BL->setText("X");
        if(!checkWin()){
            computerMove();
        }
    }
}

void GameBoard::on_BC_clicked()
{
    if(!checkLocation(7)){
        gameBoard->replace(7,"x");
        if(color == "Blue"){
            ui->BC->setStyleSheet("color : blue");
        }
        else if(color == "Red"){
            ui->BC->setStyleSheet("color : red");
        }
        else if(color == "Green"){
            ui->BC->setStyleSheet("color : green");
        }
        ui->BC->setText("X");
        if(!checkWin()){
            computerMove();
        }
    }
}

void GameBoard::on_BR_clicked()
{
    if(!checkLocation(8)){
        gameBoard->replace(8,"x");
        if(color == "Blue"){
            ui->BR->setStyleSheet("color : blue");
        }
        else if(color == "Red"){
            ui->BR->setStyleSheet("color : red");
        }
        else if(color == "Green"){
            ui->BR->setStyleSheet("color : green");
        }
        ui->BR->setText("X");
        if(!checkWin()){
            computerMove();
        }
    }
}

void GameBoard::resetBoard()
{
    for(int i = 0; i < 9; i++){
        gameBoard->replace(i,"z");
    }
    ui->TL->setText("");
    ui->TC->setText("");
    ui->TR->setText("");
    ui->CL->setText("");
    ui->CC->setText("");
    ui->CR->setText("");
    ui->BL->setText("");
    ui->BC->setText("");
    ui->BR->setText("");
}

void GameBoard::computerMove()
{
    bool moved = false;
    while(!moved){
        srand ( time(NULL) );
        int loc = rand() % 9;
        if(!checkLocation(loc)){
            gameBoard->replace(loc,"o");
            QPushButton *temp = NULL;
            switch(loc){
            case 0 :  temp = ui->TL;
                break;
            case 1: temp = ui->TC;
                break;
            case 2: temp = ui->TR;
                break;
            case 3: temp = ui->CL;
                break;
            case 4: temp = ui->CC;
                break;
            case 5: temp = ui->CR;
                break;
            case 6: temp = ui->BL;
                break;
            case 7: temp = ui->BC;
                break;
            case 8: temp = ui->BR;
                break;
            }
            if(temp != NULL){
                if(color == "Blue"){
                    temp->setStyleSheet("color : blue");
                }
                else if(color == "Red"){
                    temp->setStyleSheet("color : red");
                }
                else if(color == "Green"){
                    temp->setStyleSheet("color : green");
                }
                temp->setText("O");
                moved = true;
            }
        }
        if(isAllFinished()){
            moved = true;
        }
    }
    checkWin();
}

