#include "user.h"

user* user::User = nullptr;

void user::add_all_playlist() {
    QStringList files; // Use QVector<linked_list*>
    QString User_Name = this->get_userName();
    QDir dir("Users/" + User_Name + "/playlist/");

    if (!dir.exists()) {
        return;
    }

    QStringList filters;
    filters << "*.txt";
    dir.setNameFilters(filters);

    files = dir.entryList(QDir::Files);

    if (!files.isEmpty()) {
        for (int i = 0; i < files.size(); i++) {
            QFile file(dir.filePath(files[i]));

            if (!file.exists()) {
                continue;
            }

            if (!file.open(QIODevice::ReadOnly)) {
                QMessageBox::warning(nullptr, "No Files", "Could not open file");
                return;
            }

            QTextStream stream(&file);

            linked_list* currentList = new linked_list;  // Create a linked_list pointer for the current file

            while (!stream.atEnd()) {
                QString line = stream.readLine();
                QStringList parts = line.split(" | ");

                if (parts.size() >= 4) {
                    QString songName = parts.at(0).trimmed();
                    QString songPath = parts.at(1).trimmed();
                    QString songGenre = parts.at(2).trimmed();
                    QString songArtist = parts.at(3).trimmed();

                    Song* song = new Song(songName, songPath, songGenre, songArtist);
                    currentList->add_to_end_list(song);
                    currentList->Name = file.fileName();
                }
            }

            Playlist.append(currentList);  // Use append() with QVector<linked_list*>
        }
    } else {
        QMessageBox::warning(nullptr, "No Files", "No text files found in the directory");
    }


}

QList<Song*> user::get_linked_list_song(linked_list *L1) {
    QList<Song*> New_list;

    if (L1 == nullptr || L1->head == nullptr) {
        return New_list;
    }

    Node* temp = L1->head;

    do {
        New_list.append(temp->object);

        temp = temp->Next;
    } while (temp != L1->head);

    return New_list;
}

bool user::login_user(QString userName, QString userPass){
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
            add_all_playlist();
            return true;
        }
    }

    File.close();
    return false;
}
QList<Song*> user::get_playlist_song() {
    QList<Song*> ListA;

    for (linked_list* list : Playlist) {
        QList<Song*> ListB = get_linked_list_song(list);

        for (Song* song : ListB) {
            ListA.append(song);
        }
    }

    return ListA;
}
QVector<linked_list*> user::getPlaylist() {
    return Playlist;
}
