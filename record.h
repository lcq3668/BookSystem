#ifndef RECORD_H
#define RECORD_H
#include<time.h>
struct Record{
        char ISBN[16];
        char ID[13];
        time_t current;
        time_t deadline;
        struct Record * next;
};
typedef struct Record Record;
#endif