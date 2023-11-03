#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H
#include <song.h>
#endif // DATA_STRUCTURES_H

class Node{
public:
    Node* Next;
    Node* Prev;
    Song *object;
    Node();
    Node(Song *s);

};
//Circular Linked List
class linked_list{
public:
    Node* head;
    Node* tail;
    Node* play;
    linked_list();
    void add_to_end_list(Song *S);
    void delete_from_list(Song *S);
    Song* play_from_head(); // Left
    Song* get_next_song();  // Left
    void update_file(QString File_name); // Get the Filename and clear that file and then rewrite the playlist song name onthat file
};
