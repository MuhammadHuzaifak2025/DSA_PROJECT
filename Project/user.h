
#ifndef USER_H
#define USER_H

#include <QApplication>
#include<QString>
#include <QMessageBox>
#include "QFile"
#include "Data_structures.h"

class user
{
//    int Id;
//    static int count;
    QString userName;
    QString Email;
    QString age;
    static user *User;


    user()
    {
        age = 0;
        userName = "\0";
        Email = "\0";
    }

public:

    user(QString name,QString email,QString age) : userName(name),Email(email),age(age) { }

//    int getId() const
//    {
//        return Id;
//    }
    static user* get_instance(){
        if(User == nullptr){
            User = new user();
        }
        return User;
    }
    QString get_userName() const
    {
        return userName;
    }
    QString get_Age() const
    {
        return age;
    }
    QString get_Email() const
    {
        return Email;
    }
    void set_Name(const QString a)
    {
        userName = a;
    }
    void set_Email(const QString a)
    {
        Email = a;
    }
    bool login_user(QString userName, QString userPass){
        QFile File("userPass.txt");
        if(!File.exists())
        {
            return false;
        }
        if(!File.open(QIODevice :: ReadOnly))
        {
            QMessageBox::warning(NULL,"Login", "Cannot open txt File!");
            return false;
        }

        QTextStream stream(&File);
        while(!stream.atEnd())
        {
            QString Line = stream.readLine();
            if(Line.section("|",0,0) == userName && Line.section("|",1,1) == userPass)
            {
                File.close();
                User->userName =  userName;
                return true;
            }
        }

        File.close();
        return false;
    }
};

//int user :: count = 0;

#endif // USER_H
