#include <Data_structures.h>
#include <QFileDialog>
#include <QMessageBox>
 Node::Node(Song *s){
    Next = nullptr;
    Prev = nullptr;
    this->object = s;
}
 Node::Node(){
    Next = nullptr;
    Prev = nullptr;
}
 linked_list::linked_list(){
    head = nullptr;
    tail = nullptr;
}

void linked_list::add_to_end_list(Song *Song1){
    Node* temp = new Node(Song1);
    if(head == nullptr){
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

void linked_list::print_linked_list() {
    Node* temp = this->head;

    while (temp != nullptr) {
        QMessageBox::warning(nullptr, "No Files", temp->object->get_song());

        if (temp->Next == head) {
            break;
        }

        temp = temp->Next;
    }
}

QVector<linked_list*>  linked_list::create_playlist(QString N,  QVector<linked_list*> Playlist, Song *S){
    linked_list *NewLinked_list = new linked_list(N);

    NewLinked_list->add_to_end_list(S);
    Playlist.append(NewLinked_list);
    return Playlist;

}
