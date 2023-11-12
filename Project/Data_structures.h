#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H
#include <song.h>

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
class linked_list: protected QWidget{
public:
    Node* head;
    Node* tail;
    Node* play;
    QString Name;
    linked_list();
    void add_to_end_list(Song *S);
    void delete_from_list(Song *S);
    Song* play_from_head(); // Left
    Song* get_next_song();  // Left
    void update_to_file(QString File_name);
    void Load_from_File(QString User_Name);// Get the Filename and clear that file and then rewrite the playlist song name onthat file
    void print_linked_list();



};
#endif
