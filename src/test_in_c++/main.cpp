#include <iostream>
#include "stack.h"

using namespace std;

int main(){
    // test Stack:
    Stack<int> stack;
    for(int i=0; i <10; i++){
        stack.push(i);
    }
    cout<<"Stack: "<<stack<<endl;

    Stack<int> stack2(stack);
    cout<<"Stack 2: "<<stack2<<endl;

    while(!stack2.empty())
        cout<<"{"<<stack2.pop()<<"} "<<stack2<<endl;

    cout<<"Assigning stack back to stack2: "<<endl;
    stack2 = stack;
    cout<<"Stack: "<<stack<<endl;
    cout<<"Stack2: "<<stack2<<endl;

    return 0;
}