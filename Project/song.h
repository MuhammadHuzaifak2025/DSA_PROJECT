#ifndef SONG_H
#define SONG_H
#include <QString>
#include<QFile>
#include<QDir>
#include<QTextStream>
#include<QMessageBox>


class Song
{
    QString Name;
    QString Path;
    QString artist_name;
    QString genre;
public:
    QString get_song();
    QString get_artist();
    QString get_genre();
    QString get_path();
    void register_song(QString Name, QString Path, QString genre, QString artist );
    Song();
    Song(QString Name,QString Path, QString genre,QString artist);
    void play_song();
    QList<Song*> get_songs();
};

#endif // SONG_H
