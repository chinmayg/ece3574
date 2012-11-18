#include <QVBoxLayout>
#include <QDebug>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <QCheckBox>
#include "myfirstgui.h"

static QString ADVISEFILE = "advice.dat";
static QString WEATHERFILE = "weather.dat";
static QString REMINDERFILE = "reminder.dat";

MyFirstGUI::MyFirstGUI()
{
    createGUI();
}

MyFirstGUI::~MyFirstGUI()
{
    delete adviseButton;
    delete weatherButton;
    delete reminderButton;
    delete quitButton;
    delete te;
    delete map;
    delete reminderList;
}
void MyFirstGUI::createGUI()
{
    reminderList = new QStringList;
    reminderSentence = "";
    isInList = false;
    isChecked = false;
    //Sets the title of the main window
    setWindowTitle("myeventloop");
    map = new QSignalMapper;

    //Creates the central widget for the main window
    QWidget* boxWidget = new QWidget();
    setCentralWidget(boxWidget);

    //This will create the proper vertical layout
    QVBoxLayout* layout = new QVBoxLayout;
    boxWidget->setLayout(layout);

    //all of the item for the GUI are created
    te = new QTextEdit;
    layout->addWidget(te);
    te->setHtml("Welcome to this program!");
    adviseButton = new QPushButton("Advise",this);
    layout->addWidget(adviseButton);
    weatherButton = new QPushButton("Weather",this);
    layout->addWidget(weatherButton);
    reminderButton = new QPushButton("Reminder",this);
    layout->addWidget(reminderButton);
    quitButton = new QPushButton("Quit",this);
    layout->addWidget(quitButton);
    //mapped the signals
    map->setMapping(adviseButton,0);
    map->setMapping(weatherButton,1);
    map->setMapping(reminderButton,2);
    map->setMapping(quitButton,3);
    //This is where all of the signals and slots are assigned to the buttons
    connect(quitButton, SIGNAL(clicked()),map, SLOT(map()));
    connect(adviseButton, SIGNAL(clicked()), map, SLOT(map()));
    connect(weatherButton, SIGNAL(clicked()), map, SLOT(map()));
    connect(reminderButton, SIGNAL(clicked()), map, SLOT(map()));
    connect(map, SIGNAL(mapped(int)),this,SLOT(buttonPressedBySignal(int)));
}

void MyFirstGUI::buttonPressedBySignal(int button)
{
    QString sentence;
    if(button == 0){
        QFile test(ADVISEFILE);
        if(test.exists()){
            sentence = returnRandomSentence(ADVISEFILE);
            te->append("Advice: " + sentence);
        }
        else{
            te->append("File: " + ADVISEFILE + " does not exists");
        }
    }
    else if(button == 1){
        QFile test(WEATHERFILE);
        if(test.exists()){
            sentence = returnRandomSentence(WEATHERFILE);
            te->append("Weather: " + sentence);
        }
        else{
            te->append("File: " + WEATHERFILE + " does not exists");
        }
    }
    else if(button == 2){
        QFile test(REMINDERFILE);
        if(test.exists()){
            if(isChecked){
                sentence = reminderSentence;
            }
            else if(!isChecked && !isInList){
                sentence = returnRandomSentence(REMINDERFILE);
            }
            else if(isInList){
                if(reminderList->size() != 0){
                    srand ( time(NULL) );
                    int loc = rand() % reminderList->size();
                    sentence = reminderList->at(loc);
                }
                else{
                    sentence = "There are no reminders left";
                }
            }
            QMessageBox msgBox;
            QCheckBox checkbox("Show this message again");
            checkbox.blockSignals(true);
            checkbox.setChecked(true);
            msgBox.addButton(&checkbox, QMessageBox::ActionRole);
            msgBox.addButton(QMessageBox::Ok);
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText(sentence);
            msgBox.setParent(this,Qt::Dialog);
            msgBox.setWindowTitle("");
            msgBox.setModal(true);
            msgBox.exec();
            if ( checkbox.checkState() == Qt::Checked ){
                reminderSentence = sentence;
                isChecked = true;
            }
            else{
                isChecked = false;
                reminderList->removeOne(sentence);
            }
        }
        else{
            te->append("File: " + REMINDERFILE + " does not exists");
        }
    }
    else{
        QMessageBox::StandardButton msg;
        msg = QMessageBox::question(this,"","Are you sure you want to quit?", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        if(msg == QMessageBox::Yes){
            close();
        }
    }
}

QString MyFirstGUI::returnRandomSentence(QString Filename)
{
    QFile file(Filename);
    QString sentence;
    QString combine("");
    QStringList lines;
    srand ( time(NULL) );
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);
        while(!in.atEnd()){
            QString temp = in.readLine();
            if(temp.endsWith("\\")){
                temp.replace(temp.size()-1,1," ");
                combine.append(temp);
                if(in.atEnd())
                {
                    lines << combine;
                    if(Filename == REMINDERFILE){
                        reminderList->append(combine);
                    }
                }
            }
            else{
                combine.append(temp);
                lines << combine;
                if(Filename == REMINDERFILE){
                    reminderList->append(combine);
                }
                combine = "";
            }
        }
    }
    int loc = rand() % lines.size();
    sentence = lines[loc];
    if(Filename == REMINDERFILE){
        isInList = true;
    }
    return sentence;
}
