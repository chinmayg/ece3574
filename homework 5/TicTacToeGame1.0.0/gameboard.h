#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <QPainter>
#include <QDebug>

namespace Ui {
class GameBoard;
}

class GameBoard : public QWidget
{
    Q_OBJECT
    
public:
    explicit GameBoard(QWidget *parent = 0);
    ~GameBoard();
    void paintEvent(QPaintEvent*);
    QString getUserName();
    void setUserName(QString user);
    void setColor(QString colr);

private slots:
    void on_TL_clicked();
    void on_TC_clicked();
    void on_TR_clicked();
    void on_CL_clicked();
    void on_CC_clicked();
    void on_CR_clicked();
    void on_BL_clicked();
    void on_BC_clicked();
    void on_BR_clicked();

private:
    Ui::GameBoard *ui;
    QString usrName;
    QString color;
    QStringList* gameBoard;
    bool checkLocation(int x);
    bool checkWin();
    void resetBoard();
    void computerMove();
    bool isAllFinished();
    int uCount;
    int cCount;
    int dCount;
};

#endif // GAMEBOARD_H
