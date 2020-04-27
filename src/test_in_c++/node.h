#ifndef NODE_H
#define NODE_H
#include <cassert>
#include <cstddef>

template <class T>
struct Node{
    Node(){
        this->item = NULL;
        this->next = nullptr;
    }

    Node(T item){
        this->item = item;
        this->next = nullptr;
    }


    T item;
    Node<T>* next;
};

// delete all the nodes with a given head pointer
template <class T>
void delete_all(Node<T>*& head_ptr){
    while(head_ptr != nullptr){
        Node<T>* walker = head_ptr;
        head_ptr = head_ptr->next;
        delete walker;
    }
    assert(head_ptr == nullptr);   // head_ptr should be nullptr by the end of the delete process
}

template <class T>
Node<T>* insert_head(Node<T>*& head, T item){
    Node<T>* temp = new Node<T>(item);
    temp->next = head;
    head = temp;
    return temp;
}

template <class T>
Node<T>* insert_after(Node<T>*& head, Node<T>* afterThis, const T& item){
    if(afterThis == nullptr || head == nullptr){
        return insert_head(head, item);
    }
    else{
        Node<T>* temp = new Node<T>(item);
        temp->next = afterThis->next;
        afterThis->next = temp;
        return temp;
    }
}


template <class T>
Node<T>* copy_list (const Node<T>* src, Node<T>*& dest){
    if(src == nullptr){
        dest = nullptr;
        return nullptr;
    }
    else{
        Node<T>* walker = nullptr;
        while(src != nullptr){
            walker = insert_after(dest, walker, src->item);
            src = src->next;
        }

        //assign the last element of dest to be nullptr
        walker->next = nullptr;
        return walker;
    }

}

template <class T>
T delete_head(Node<T>*& head_ptr){
    assert(head_ptr != nullptr);
    Node<T>* temp = head_ptr;
    head_ptr = head_ptr->next;
    T val = temp->item;
    delete temp;
    return val;
}





#endif // NODE_H