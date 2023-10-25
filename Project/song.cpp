#include "song.h"

Song::Song()
{

}
QString Song::get_artist(){
    return artist_name;
}

QString Song::get_genre(){
    return genre;
}
QString Song::get_song(){
    return Name;
}
QString Song::get_path(){
    return Path;
}
Song::Song(QString Name,QString Path, QString genre,QString artist){
    this->Name = Name;
    this->Path = Path;
    this->genre = genre;
    this->artist_name = artist;
}
void Song::play_song(){
//    Dani Implement this in the class of song
}
void Song::register_song(QString Name, QString Path, QString genre, QString artist ){

    QFile File("Songs.txt");
    if (!File.exists()) {
        File.open(QIODevice::WriteOnly);
        if (File.exists()) {
            QMessageBox::warning(NULL, "Login", "File Created");
        }
    }

    if (!File.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::warning(NULL, "Login", "Cannot open txt File!");
        return;
    }

    QTextStream stream(&File);

    while (!stream.atEnd()) {
        QString Line = stream.readLine();
        if (Line.section("|", 0, 0) == Name || Line.section("|", 1, 1) == (" "+Path + " ")) {
            QMessageBox::warning(NULL, "Login", "Song Already Registered");
            File.close();
            return;
        }
    }
    File.seek(File.size());
    stream << Name + " | " << Path + " | "<< genre + " | "<< artist + " | " << "\n";
    File.close();
    QMessageBox::warning(NULL, "Login", "Song Registered");


}
