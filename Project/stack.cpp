#include "stack.h"
#include<QList>

Stack_Node::Stack_Node()
{
    next = NULL;
}

Stack_Node::Stack_Node(Song a)
{
    next = NULL;
    s1 = Song(a.get_song(),a.get_path(),a.get_genre(),a.get_artist());
}
Stack::Stack()
{
    head = NULL;
}

void Stack :: Push(Song a)
{
    Stack_Node *n = new Stack_Node(a);
    if(head == NULL)
    {
        head = n;
        return;
    }

    n->next = head;
    head = n;
    return;
}

void Stack :: Pop()
{
    if(head==NULL)
    {
        return;
    }
    Stack_Node *temp = head;
    head = head -> next;
    delete temp;
}

Song Stack :: Peek()
{
    Song song;
    if(head == NULL)
    {

        QMessageBox::warning(NULL,"Stack", "Stack Empty!");
        return song;
    }

    song =  Song(head->s1.get_song(),head->s1.get_path(),head->s1.get_genre(),head->s1.get_artist());
    return song;
}

QList<Song> Stack :: get_all_history(){
    Stack_Node *temp  = head;
    QList<Song> History_songs;
    while(temp != NULL){
        History_songs.append(temp->s1);
        temp = temp->next;
    }
    return History_songs;
}

void Stack::File_History(QString filePath){
    QList<Song> Hist = get_all_history();
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);

        // Iterate through the history and write each Song's content to the file
        for (Song& song : Hist) {
            out<< song.get_song()+ " | " << song.get_path()+ " | "<< song.get_genre()+ " | "<< song.get_artist() + " | " << "\n";
        }

        // Close the file
        file.close();
    } else {
        // Handle the case when the file cannot be opened
        qDebug() << "Error opening file for writing:" << file.errorString();
    }
}

Stack Stack::Load_to_file(QString filepath){
    Stack S;
    QFile file(filepath);

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
            Song song(songName, songPath, songGenre, songArtist);
            S.Push(song);
        }
    }
    return S;
}
