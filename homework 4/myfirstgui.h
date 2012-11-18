#ifndef MYFIRSTGUI_H
#define MYFIRSTGUI_H
#include <QPushButton>
#include <QTextEdit>
#include <QString>
#include <QFile>
#include <QSignalMapper>
#include <QErrorMessage>
#include <QMessageBox>
#include <QMainWindow>

class MyFirstGUI : public QMainWindow
{
    Q_OBJECT
public:
    MyFirstGUI();
    ~MyFirstGUI();
private slots:
    void buttonPressedBySignal(int button);

private:
    QPushButton* adviseButton;
    QPushButton* weatherButton;
    QPushButton* reminderButton;
    QPushButton* quitButton;
    QTextEdit* te;
    QSignalMapper* map;
    QStringList* reminderList;
    QString reminderSentence;
    bool isInList;
    bool isChecked;
    QString returnRandomSentence(QString Filename);
    void createGUI();
};

#endif // MYFIRSTGUI_H
