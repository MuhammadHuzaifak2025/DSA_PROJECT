
#ifndef USER_H
#define USER_H

#include <QApplication>
#include<QString>

class user
{
//    int Id;
//    static int count;
    QString userName;
    QString Email;
    QString age;

public:
    user()
    {
        age = 0;
        userName = "\0";
        Email = "\0";
//        Id = count;
    }
    user(QString name,QString email,QString age) : userName(name),Email(email),age(age) { }

//    int getId() const
//    {
//        return Id;
//    }
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
};

//int user :: count = 0;

#endif // USER_H
