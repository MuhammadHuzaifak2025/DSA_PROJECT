#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <user.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_userPass->setEchoMode(QLineEdit::Password);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Login_clicked()
{
    user* u = user::get_instance();
    if(u->login_user(ui -> lineEdit_userName -> text(),ui -> lineEdit_userPass -> text()))
    {
        spopify = new spotify;
        this->hide();
        spopify->show();
    }
    else
    {
        QMessageBox :: warning(this,"Login","Invalid Username/Password");
        ui->lineEdit_userName->clear();
        ui->lineEdit_userPass->clear();
    }
}

bool MainWindow :: loginUser()
{
    QString userName = ui -> lineEdit_userName -> text();
    QString userPass = ui -> lineEdit_userPass -> text();

    QFile File("userPass.txt");
    if(!File.exists())
    {
        return false;
    }
    if(!File.open(QIODevice :: ReadOnly))
    {
        QMessageBox :: warning(this,"Login", "Cannot open txt File!");
        return false;
    }

    QTextStream stream(&File);
    while(!stream.atEnd())
    {
        QString Line = stream.readLine();
        if(Line.section("|",0,0) == userName && Line.section("|",1,1) == userPass)
        {
            File.close();
            return true;
        }
    }

    File.close();
    return false;
}

void MainWindow::on_pushButton_newUser_clicked()
{
//    hide();
    newWindow = new newUser(this);
    newWindow->show();
}

