#ifndef STACK_H
#define STACK_H
#include <song.h>
#include "QMessageBox"
class Stack_Node
{
public:
    Stack_Node* next;
    Song s1;

    Stack_Node();
    Stack_Node(Song a);
};

class Stack
{
public:
    Stack_Node *head;
    Stack();
    void Push(Song a);
    void Pop();
    Song Peek();
};

#endif // STACK_H
