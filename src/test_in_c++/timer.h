#ifndef TIME_H
#define TIME_H
#include <time.h>

class Timer{
public:
    Timer(): startTime(clock()), endTime(clock()){}

    void start(){
        startTime = clock();
    }

    void stop(){
        endTime = clock();
    }

    float duration(){
        return (float(endTime) - float(startTime)) / CLOCKS_PER_SEC;
    }


private:
    clock_t startTime;
    clock_t endTime;

};

#endif