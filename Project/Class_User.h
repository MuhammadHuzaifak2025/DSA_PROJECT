#include <QString>
#ifndef CLASS_USER_H
#define CLASS_USER_H
class User{
private:
    QString User_name,email;
    bool Gender;
    int age;
    QString current_logged_in;

public:
    QString get_current_logged_user(); //Retrun the bool if the user is logged in.
    QString get_email();
    bool Login(QString username, QString Password);
//    Que object; Object for Que
//    Linked_list Object for playlist
    bool Autoplay;
};

#endif // CLASS_USER_H
