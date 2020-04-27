#ifndef STACK_H
#define STACK_H
#include "list.h"

template <class T>
class Stack{
public:
    Stack();

    void push(T item);
    void clear();
    T pop();
    T top();
    bool empty();
    int length();

    friend ostream& operator <<(ostream& outs, const Stack& printMe){
        outs<<printMe.stack;
        return outs;
    }

private:
    List<T> stack;
};

template <class T>
Stack<T>::Stack(){
    stack = List<T>();
}

template <class T>
void Stack<T>::push(T item){
    stack.insert(item);
}

template <class T>
void Stack<T>::clear(){
    stack.clear();
}

template <class T>
T Stack<T>::pop(){
    return stack.remove();
}

template <class T>
T Stack<T>::top(){
    return stack.top();
}

template <class T>
bool Stack<T>::empty(){
    return stack.empty();
}

template <class T>
int Stack<T>::length(){
    return stack.length();
}



#endif // STACK_H