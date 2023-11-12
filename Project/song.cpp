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
        // Create the file if it doesn't exist
        if (File.open(QIODevice::ReadWrite)) {
            File.close();  // Close the file after creating
        } else {
            QMessageBox::warning(nullptr, "ERROR", "Cannot create Songs.txt!");
            return;
        }
    }

    if (!File.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "ERROR", "Cannot open Songs.txt for appending!");
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
QList<Song*> Song::get_songs() {
    QFile file("Songs.txt");
    if (!file.exists()) {
        return QList<Song*>(); // Return an empty list if the file doesn't exist.
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "Failed", "Cannot open the text file!");
        return QList<Song*>();
    }

    QList<Song*> songList; // Create a list to store the Song objects.

    QTextStream stream(&file);
    while (!stream.atEnd()) {
        QString line = stream.readLine();
        QStringList parts = line.split(" | ");

        if (parts.size() >= 4) {
            QString songName = parts.at(0).trimmed();
            QString songPath = parts.at(1).trimmed();
            QString songGenre = parts.at(2).trimmed();
            QString songArtist = parts.at(3).trimmed();

            // Create a new Song object and add it to the list.
            Song *song = new Song(songName, songPath, songGenre, songArtist);
            songList.append(song);
        }
    }

    file.close();

    return songList;
}
