#include <iostream>
#include "stack.h"
#include <stack>
#include "timer.h" 

using namespace std;

static const int ELEMENTS = 1000000;

void testStandardStack(Timer& t);
void testImplementStack(Timer& t);

int main(){
    // test Stack:
    Timer t;

    testImplementStack(t);
    cout<<"\n\n\n\n----------------------------------------------------\n";
    testStandardStack(t);

    return 0;
}

void testImplementStack(Timer& t){
    t.start();
    Stack<int> stack;
    t.stop();
    cout<<"Creating stack takes: "<<t.duration()<<" seconds\n";

    t.start();
    for(int i=0; i <ELEMENTS; i++){
        stack.push(i);
    }
    t.stop();
    // cout<<"Stack: "<<stack<<endl;
    cout<<"Pushing "<<ELEMENTS<<" elements into stack take: "<<t.duration()<<" seconds\n";


    t.start();
    for(int i=0; i<ELEMENTS;i++){
        stack.pop();
    }
    t.stop();
    cout<<"Popping "<<ELEMENTS<<" elements from the stack take: "<<t.duration()<<" seconds\n";
}

void testStandardStack(Timer& t){
    t.start();
    stack<int> s;
    t.stop();
    cout<<"Creating stack takes: "<<t.duration()<<" seconds\n";

    t.start();
    for(int i=0; i <ELEMENTS; i++){
        s.push(i);
    }
    t.stop();
    // cout<<"Stack: "<<stack<<endl;
    cout<<"Pushing "<<ELEMENTS<<" elements into stack take: "<<t.duration()<<" seconds\n";


    t.start();
    for(int i=0; i<ELEMENTS;i++){
        s.pop();
    }
    t.stop();
    cout<<"Popping "<<ELEMENTS<<" elements from the stack take: "<<t.duration()<<" seconds\n";
}
