#ifndef STACK_H
#define STACK_H
#include <song.h>
#include "QMessageBox"
#include <QFile>
#include<QTextStream>
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
    QList<Song> get_all_history();
    void File_History(QString filePath);
    void Load_to_file(QString filepath);

};

#endif // STACK_H
