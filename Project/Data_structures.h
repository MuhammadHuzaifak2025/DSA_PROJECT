#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H
#include <song.h>
#include<QWidget>

//  DATA_STRUCTURES_H

class Node{
public:
    Node* Next;
    Node* Prev;
    Song *object;
    Node();
    Node(Song *s);
//    user U;

};
//Circular Linked List
class linked_list: public QWidget{
public:
    Node* head;
    Node* tail;
    Node* play;
    QString Name;
    linked_list();
    linked_list(QString Name){
        this->Name = Name;
        head = NULL;
        tail = NULL;
    }
    void add_to_end_list(Song *S);
    void delete_from_list(Song *S);
    Song* play_from_head(); // Left
    Song* get_next_song();  // Left
    void update_to_file(QString File_name);
    linked_list Load_from_File(QString User_Name);// Get the Filename and clear that file and then rewrite the playlist song name onthat file
    void print_linked_list();
    QVector<linked_list*> create_playlist(QString Name, QVector<linked_list*> Playlist, Song* S);
    void add_to_playlist(linked_list* A, Song* S);
};

#endif
