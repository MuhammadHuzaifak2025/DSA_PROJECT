#include "stack.h"

Node::Node()
{
    next = NULL;
}

Node::Node(Song a)
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
    Node *n = new Node(a);
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
    Node *temp = head;
    head = head -> next;
    delete temp;
}

Song Stack :: Peek()
{
    Song song;
    if(head == NULL)
    {
        QMessageBox :: warning(this,"Stack", "Stack Empty!");
        return song;
    }

    song =  Song(head->s1.get_song(),head->s1.get_path(),head->s1.get_genre(),head->s1.get_artist());
    return song;
}
