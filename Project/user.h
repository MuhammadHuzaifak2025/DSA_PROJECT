
#ifndef USER_H
#define USER_H

#include <QApplication>
#include<QString>
#include <QMessageBox>
#include "QFile"
#include "Data_structures.h"

#include<QVector>
#include "stack.h"

class user : public linked_list
{
//    int Id;
//    static int count;
    QString userName;
    QString Email;
    QString age;



//    QVector<linked_list*> Playlist; //Playlist


    static user *User;


    user()
    {
        age = 0;
        userName = "\0";
        Email = "\0";
    }

public:

    QVector<linked_list*> Playlist; //Playlist
    Stack History;
    linked_list* S1;
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
    void add_all_playlist();
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
    bool login_user(QString userName, QString userPass);
    QList<Song*> get_linked_list_song(linked_list *L1);
    QList<Song*> get_playlist_song();
    QVector<linked_list*> getPlaylist();
    QStringList getPlaylistNames();

    void SetPlaylist(QVector<linked_list*> A);
    void add_playlist(QString Name, Song *NewSong);

};

//int user :: count = 0;

#endif // USER_H
