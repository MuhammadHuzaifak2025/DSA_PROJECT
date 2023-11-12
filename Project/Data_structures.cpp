#include <Data_structures.h>
#include <QFileDialog>
#include <QMessageBox>
 Node::Node(Song *s){
    Next = nullptr;
    Prev = nullptr;
    this->object = s;
}
 Node::Node(){
    Next = nullptr;
    Prev = nullptr;
}
 linked_list::linked_list(){
    head = nullptr;
    tail = nullptr;
}

void linked_list::add_to_end_list(Song *Song1){
    Node* temp = new Node(Song1);
    if(head == nullptr){
        head = tail = temp;
        tail->Next = head;
        return;
    }
    tail->Next = temp;
    temp->Prev = tail;
    tail = temp;
    tail->Next = head;
    return;
}
void linked_list::delete_from_list(Song *s){
    Node* temp = head;
    while(true)
    {
        if(temp == tail){
            if(temp->object->get_song() == s->get_song()){
                Node* temporary = temp->Prev;
                temporary->Next= temp->Next;
                temp->Next->Prev = temporary;
                delete temp;
                return;
            }
            return;
        }
        if(temp->object->get_song() == s->get_song()){
            Node* temporary = temp->Prev;
            temporary->Next= temp->Next;
            temp->Next->Prev = temporary;
            delete temp;
            return;
        }
        temp = temp->Next;
    }
}
void linked_list::Load_from_File(QString User_Name) {
    QDir dir("Users/" + User_Name + "/playlist/");

    if (!dir.exists()) {
        QMessageBox::warning(nullptr, "Error", "Directory does not exist");
        return;
    }

    QStringList filters;
    filters << "*.txt";
    dir.setNameFilters(filters);

    QStringList files = dir.entryList(QDir::Files);

    if (!files.isEmpty()) {
        QMessageBox::warning(nullptr, "Files Found", "Found " + QString::number(files.size()) + " text file(s)");

        // Create a single linked list outside the loop
        linked_list *allSongsList = new linked_list[files.size()];
        int i = 0;

        for (const QString& fileName : files) {
            QFile file(fileName);

            if (!file.exists()) {
                // Skip the iteration if the file does not exist
                continue;
            }
            file.open(QIODevice::ReadOnly);
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
                    allSongsList[i].add_to_end_list(song);

                }
            }
            i++;
        }

        // Print the complete linked list after processing all files
        for(int j = 0; j<i; j++){
            allSongsList[j].print_linked_list();
        }

        // Don't forget to release the allocated memory
//        allSongsList.clear(); // Assuming you have a clear() function to release memory
    } else {
        QMessageBox::warning(nullptr, "No Files", "No text files found in the directory");
    }
}

void linked_list::print_linked_list() {
    Node* temp = this->head;

    while (temp != nullptr) {
        // Use temp->object to access the data of the current node
        QMessageBox::warning(nullptr, "No Files", temp->object->get_song());

        if (temp->Next == head) {
//            QMessageBox::warning(nullptr, "Debug", "Circular linked list detected!");
            break;
        }

        temp = temp->Next;
    }
}
