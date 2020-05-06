#include <iostream>
#include "stack.h"
#include <stack>
#include "timer.h" 

using namespace std;

// static const int ELEMENTS = 100000000;

void testStandardStack(Timer& t, const int& numOfElements, const int& numOfIterations);
void testImplementStack(Timer& t, const int& numOfElements, const int& numOfIterations);

int main(int argc, char** argv){
    if(argc >= 2){
        int numOfElements =  atoi(argv[1]);
        int numOfIterations = atoi(argv[2]);
        
        // test Stack:
        Timer t;

        testImplementStack(t, numOfElements, numOfIterations);
        cout<<"\n\n\n\n----------------------------------------------------\n";
        cout<<"STL Stack Performance:\n\n";
        testStandardStack(t, numOfElements, numOfIterations);
    }
    else{
        cout<<"There have to be at least 1 argument!";
    }

    return 0;
}

void testImplementStack(Timer& t, const int& numOfElements, const int& numOfIterations){
    float totalInitTime = 0;
    float totalPushTime = 0;
    float totalPopTime = 0;
    
    for(int i=0; i<numOfIterations; i++){
        t.start();
        Stack<int> stack;
        t.stop();
        totalInitTime += t.duration();
        // cout<<"Creating stack takes: "<<t.duration()<<" seconds\n";

        t.start();
        for(int i=0; i <numOfElements; i++){
            stack.push(i);
        }
        t.stop();
        totalPushTime += t.duration();
        // cout<<"Pushing "<<numOfElements<<" elements into stack take: "<<t.duration()<<" seconds\n";


        t.start();
        for(int i=0; i<numOfElements;i++){
            stack.pop();
        }
        t.stop();
        totalPopTime += t.duration();
        // cout<<"Popping "<<numOfElements<<" elements from the stack take: "<<t.duration()<<" seconds\n";
    }

    // cout<<totalInitTime<<"\t"<<totalPushTime<<"\t"<<totalPopTime<<"\n";

    cout<<"Average time to create stack: "<<( totalInitTime / numOfIterations)<<" seconds\n";
    cout<<"Average time to push "<<numOfElements<<" elements into stack: "<<( totalPushTime / numOfIterations)<<" seconds\n";
    cout<<"Average time to pop "<<numOfElements<<" elements from the stack: "<<( totalPopTime / numOfIterations)<<" seconds\n";
}

void testStandardStack(Timer& t, const int& numOfElements, const int& numOfIterations){
    float totalInitTime = 0;
    float totalPushTime = 0;
    float totalPopTime = 0;
    
    for(int i=0; i<numOfIterations; i++){
        t.start();
        stack<int> stack;
        t.stop();
        totalInitTime += t.duration();
        // cout<<"Creating stack takes: "<<t.duration()<<" seconds\n";

        t.start();
        for(int i=0; i <numOfElements; i++){
            stack.push(i);
        }
        t.stop();
        totalPushTime += t.duration();
        // cout<<"Pushing "<<numOfElements<<" elements into stack take: "<<t.duration()<<" seconds\n";


        t.start();
        for(int i=0; i<numOfElements;i++){
            stack.pop();
        }
        t.stop();
        totalPopTime += t.duration();
        // cout<<"Popping "<<numOfElements<<" elements from the stack take: "<<t.duration()<<" seconds\n";
    }

    // cout<<totalInitTime<<"\t"<<totalPushTime<<"\t"<<totalPopTime<<"\n";

    cout<<"Average time to create stack: "<<( totalInitTime / numOfIterations)<<" seconds\n";
    cout<<"Average time to push "<<numOfElements<<" elements into stack: "<<( totalPushTime / numOfIterations)<<" seconds\n";
    cout<<"Average time to pop "<<numOfElements<<" elements from the stack: "<<( totalPopTime / numOfIterations)<<" seconds\n";
}
