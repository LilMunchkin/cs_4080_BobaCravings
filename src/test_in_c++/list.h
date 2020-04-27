#ifndef LIST_H
#define LIST_H
#include "node.h"
#include <cassert>
#include <iostream>

using namespace std;

template <class T>
class List{
public:
    List();

    ~List();
    List<T>& operator =(const List<T>& rhs);
    List(const List<T>& src);

    void insert(T item);
    T remove();
    T top();
    void clear();
    bool empty();
    int length();

    friend ostream& operator <<(ostream& outs, List<T> printMe){
        Node<T>* walker = printMe.head_ptr;
        
        while(walker != nullptr){
            outs<<"["<<walker->item<<"]->";
            walker = walker->next;
        }
        if(walker ==nullptr){
            outs<<"|||";
        }
        return outs;
    }

private:
    Node<T>* head_ptr;
    int size;
};

template <class T>
List<T>::List(){
    this->head_ptr = nullptr;
    this->size =  0;
}

template <class T>
List<T>::~List(){
    delete_all(this->head_ptr);
}

template <class T>
List<T>& List<T>::operator =(const List<T>& rhs){
    if(this != &rhs){
        delete_all(this->head_ptr);
        copy_list(rhs.head_ptr, this->head_ptr);
        this->size = rhs.size;
    }
    return *this;
}

template <class T>
List<T>::List(const List<T>& src){
    copy_list(src.head_ptr, this->head_ptr);
    this->size = src.size;
}

template <class T>
void List<T>::insert(T item){
    insert_head(this->head_ptr, item);
    size++;
}

template <class T>
T List<T>::remove(){
    assert(this->size > 0);
    T temp = delete_head(this->head_ptr);
    size--;
    return temp;
}

template <class T>
T List<T>::top(){
    return head_ptr->item;
}

template <class T>
void List<T>::clear(){
    delete_all(this->head_ptr);
    this->size = 0;
}

template <class T>
bool List<T>::empty(){
    if(size != 0)
        return false;
    else
        return true;
}

template <class T>
int List<T>::length(){
    return this->size;
}







#endif // LIST_H