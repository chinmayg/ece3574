#include "mainlogin.h"
#include "ui_mainlogin.h"

MainLogin::MainLogin(QWidget *parent) : QWidget(parent), ui(new Ui::MainLogin)
{
    ui->setupUi(this);
    ui->PassLine->setEchoMode( QLineEdit::Password );
}

QDataStream &operator>>(QDataStream &in, MemberData &m)
{
    in >> m.name;
    in >> m.color;
    in >> m.passwordDigest;
    return in;
}
MainLogin::~MainLogin()
{
    delete ui;
}

void MainLogin::on_Login_clicked()
{
    QList<MemberData> members;
    QMessageBox msgBox;
    QString color1 = "";
    bool userCheck = false;
    bool passwordCheck = false;
    //Check if password is correct
    QFile file("passwords.dat");
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_4_6);
    in >> members;
    for(int i = 0; i < members.size();i++){
        if(ui->UserNameLine->text() == members[i].name){
            userCheck = true;
        }
    }
    if(userCheck){
        for(int i = 0; i < members.size();i++){
            QByteArray tempPass = ui->PassLine->text().toUtf8();
            tempPass = QCryptographicHash::hash(tempPass, QCryptographicHash::Sha1);
            if(tempPass.toHex() == members[i].passwordDigest.toHex()){
                passwordCheck = true;
                color1 = members[i].color;
            }
        }
    }
    if(userCheck && passwordCheck){
        //Go to login screen
        file.close();
        Welcome* welcomeScreen = new Welcome();
        welcomeScreen->setUserName(ui->UserNameLine->text());
        MainWindow* temp = qobject_cast<MainWindow*>(parent());
        welcomeScreen->setParent(temp);
        temp->changePanel(welcomeScreen);
        temp->setWindowTitle("Welcome");
        temp->setUserName(ui->UserNameLine->text());
        temp->setColor(color1);
        temp->enablerForWelcome();
        temp = NULL;
        delete temp;
    }
    else {
        msgBox.setText("The incorrect username or password, please re-enter");
        msgBox.setWindowTitle("");
        msgBox.setModal(true);
        msgBox.exec();
    }
}

void MainLogin::on_Exit_clicked()
{
    MainWindow* temp = qobject_cast<MainWindow*>(parent());
    temp->close();
}
