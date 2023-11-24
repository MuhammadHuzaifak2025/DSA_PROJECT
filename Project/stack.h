#ifndef STACK_H
#define STACK_H
#include <song.h>

class Node
{
public:
    Node* next;
    Song s1;

    Node();
    Node(Song a);
};

class Stack
{
public:
    Node *head;
    Stack();
    void Push(Song a);
    void Pop();
    Song Peek();
};

#endif // STACK_H
