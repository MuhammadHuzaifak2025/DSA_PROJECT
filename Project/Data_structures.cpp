#include <Data_structures.h>

 Node::Node(Song *s){
    Next = NULL;
    this->object = s;
}
 Node::Node(){
    Next = NULL;
    Prev = NULL;
}
 linked_list::linked_list(){
    head = NULL;
    tail = NULL;
}

void linked_list::add_to_end_list(Song *Song1){
    Node* temp = new Node(Song1);
    if(head == NULL){
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
