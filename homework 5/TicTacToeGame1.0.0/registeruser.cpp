#include "registeruser.h"
#include "ui_registeruser.h"

RegisterUser::RegisterUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterUser)
{
    ui->setupUi(this);
    ui->PassLine->setEchoMode( QLineEdit::Password );
    ui->RePassLine->setEchoMode( QLineEdit::Password );
}

QDataStream &operator>>(QDataStream &in, RegisterData &m)
{
    in >> m.name;
    in >> m.color;
    in >> m.passwordDigest;
    return in;
}

QDataStream &operator<<(QDataStream &out, const RegisterData &m)
{
    out << m.name;
    out << m.color;
    out << m.passwordDigest;
    return out;
}

RegisterUser::~RegisterUser()
{
    delete ui;
}

void RegisterUser::on_Ok_clicked()
{
    QMessageBox msgBox;
    bool error = false;
    QList<RegisterData> members;
    //Check if password is correct
    QFile file("passwords.dat");
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_4_6);
    in >> members;
    file.close();
    for(int i = 0; i < members.size();i++){
        if(ui->UserNameLine->text() == members[i].name){ //looks for user data
            msgBox.setText("This userName already exists in the database, please enter a new one");
            msgBox.setWindowTitle("");
            msgBox.setModal(true);
            msgBox.exec();
            error = true;
        }
    }
    if(ui->PassLine->text() == ui->RePassLine->text()){ //checks if the new password is type correctly
        QByteArray tempPass = ui->RePassLine->text().toUtf8();
        RegisterData tempMember;
        tempPass = QCryptographicHash::hash(tempPass, QCryptographicHash::Sha1);
        tempMember.name = ui->UserNameLine->text();
        tempMember.passwordDigest = tempPass; // adds to member structure list
        tempMember.color = ui->comboBox->currentText();
        members.append(tempMember);
        error = false;
    }
    else{
        msgBox.setText("The new and reentered passwords do not match, please re-enter");
        msgBox.setWindowTitle("");
        msgBox.setModal(true);
        msgBox.exec();
        error = true;
    }
    if(!error){
        QDataStream out(&file);
        file.open(QIODevice::WriteOnly);
        out << members;
        file.close();
        //Return to login screen
        MainLogin* loginScrn = new MainLogin();
        MainWindow* temp = qobject_cast<MainWindow*>(parent());
        temp->setWindowTitle("Tic-Tac-Toe");
        temp->changePanel(loginScrn);
        temp->enablerForMainLogin();
        temp = NULL;
        delete temp;
    }
}

void RegisterUser::on_Cancel_clicked()
{
    MainLogin* loginScrn = new MainLogin();
    MainWindow* temp = qobject_cast<MainWindow*>(parent());
    temp->setWindowTitle("Tic-Tac-Toe");
    temp->changePanel(loginScrn);
    temp->enablerForMainLogin();
    temp = NULL;
    delete temp;
}
