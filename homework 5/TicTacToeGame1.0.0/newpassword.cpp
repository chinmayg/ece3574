#include "newpassword.h"
#include "ui_newpassword.h"

NewPassword::NewPassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewPassword)
{
    ui->setupUi(this);
    usrName = "";
    ui->oldpassline->setEchoMode( QLineEdit::Password );
    ui->NewPassLine->setEchoMode( QLineEdit::Password );
    ui->RePassLine->setEchoMode( QLineEdit::Password );
}

QDataStream &operator>>(QDataStream &in, NewPasswordData &m)
{
    in >> m.name;
    in >> m.color;
    in >> m.passwordDigest;
    return in;
}

QDataStream &operator<<(QDataStream &out, const NewPasswordData &m)
{
    out << m.name;
    out << m.color;
    out << m.passwordDigest;
    return out;
}

void NewPassword::setUserName(QString text)
{
    usrName = text;
    ui->userName->setText("Changing Password for user " + usrName);
}

NewPassword::~NewPassword()
{
    delete ui;
}

void NewPassword::on_ok_clicked()
{
    QMessageBox msgBox;
    bool error = false;
    QList<NewPasswordData> members;
    //Check if password is correct
    QFile file("passwords.dat");
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_4_6);
    in >> members;
    file.close();
    for(int i = 0; i < members.size();i++){
        if(usrName == members[i].name){ //looks for user data
            QByteArray tempPass = ui->oldpassline->text().toUtf8();
            tempPass = QCryptographicHash::hash(tempPass, QCryptographicHash::Sha1);
            if(tempPass.toHex() == members[i].passwordDigest.toHex()){ //checks the old password
                if(ui->NewPassLine->text() == ui->RePassLine->text()){ //checks if the new password is type correctly
                    tempPass = ui->RePassLine->text().toUtf8();
                    tempPass = QCryptographicHash::hash(tempPass, QCryptographicHash::Sha1);
                    members[i].passwordDigest = tempPass; // adds to member structure list
                    members[i].color = ui->comboBox->currentText();
                    error = false;
                }
                else{
                    msgBox.setText("The new and reentered passwords do not match, please re-enter");
                    msgBox.setWindowTitle("");
                    msgBox.setModal(true);
                    msgBox.exec();
                    error = true;
                }
            }
            else{
                msgBox.setText("The old password do not match, please re-enter");
                msgBox.setWindowTitle("");
                msgBox.setModal(true);
                msgBox.exec();
                error = true;
            }
        }
    }
    if(!error){
        QDataStream out(&file);
        file.open(QIODevice::WriteOnly);
        out << members;
        file.close();
        Welcome* loginScrn = new Welcome();
        loginScrn->setUserName(usrName);
        MainWindow* temp = qobject_cast<MainWindow*>(parent());
        temp->setWindowTitle("Welcome");
        temp->changePanel(loginScrn);
        temp->enablerForWelcome();
        temp = NULL;
        delete temp;
    }
}

void NewPassword::on_cancel_clicked()
{
    Welcome* loginScrn = new Welcome();
    loginScrn->setUserName(usrName);
    MainWindow* temp = qobject_cast<MainWindow*>(parent());
    temp->setWindowTitle("Welcome");
    temp->changePanel(loginScrn);
    temp->enablerForWelcome();
    temp = NULL;
    delete temp;
}
