#include "newuser.h"
#include "ui_newuser.h"
#include "user.h"


newUser::newUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newUser)
{
    ui->setupUi(this);
    ui->lineEdit_pass->setEchoMode(QLineEdit::Password);
}

newUser::~newUser()
{
    delete ui;
}

bool isUnique(QString name)
{
    QFile File("userPass.txt");
    if(!File.exists())
    {
        return true;
    }
    if(!File.open(QIODevice::ReadOnly))
    {
        qCritical() << "Cannot open txt File!";
        return false;
    }

    QTextStream stream(&File);
    while(!stream.atEnd())
    {
        QString Line = stream.readLine();
        if(Line.section("|",0,0) == name)
        {
            return false;
        }
    }

    File.close();
    return true;
}

void newUser::on_pushButton_Login_clicked()
{
    QString userName = ui -> lineEdit_userName -> text();
    QString userPass = ui -> lineEdit_pass -> text();
    QString email = ui -> lineEdit_email -> text();
    QString age = ui -> lineEdit_age -> text();

    if(age.toInt() < 18 || age.toInt() >= 124)
    {
        QMessageBox :: warning(this,"New User","Enter Valid Age!");
        ui -> lineEdit_age -> clear();

    }
    else if(!isUnique(userName))
    {
        QMessageBox :: warning(this,"New User","Username Already Exists!");
        ui -> lineEdit_userName -> clear();
    }

    else if(userPass.length() < 5)
    {
        QMessageBox :: warning(this,"New User","Password Too Short!");
        ui -> lineEdit_pass -> clear();
    }
    else
    {
        user a(userName,email,age);

        QFile File("userPass.txt");
        if(!File.open((QIODevice::ReadWrite) | (QIODevice :: Append)))
        {
            QMessageBox :: warning(this,"New User(1)", "Cannot open txt File!");
            return;
        }

        QTextStream stream(&File);
        stream << a.get_userName() + "|";
        stream << userPass + "\n";

        File.close();

        QDir dir;
        dir.mkpath("Users/"+a.get_userName()+"/playlist");
        QFile NUser("Users/" + a.get_userName()+"/"+ "User_detail.txt");

        if(!NUser.open((QIODevice::ReadWrite) | (QIODevice :: Append)))
        {
            QMessageBox :: warning(this,"New User(2)", "Cannot open txt File!");
            return;
        }

        QTextStream stream1(&NUser);

        //    stream1 << a.getId() + "\n";
        stream1 << a.get_userName() + "\n";
        stream1 << userPass + "\n";
        stream1 << a.get_Email() + "\n";
        stream1 << a.get_Age() + "\n";

        NUser.close();

        QMessageBox :: information(this,"New User", "User Created Successfully");
        this->close();
    }
}
