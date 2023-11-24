#include "stack.h"

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
