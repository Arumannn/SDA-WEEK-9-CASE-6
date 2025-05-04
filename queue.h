#include "boolean.h"
#ifndef QUEUE_H
#define QUEUE_H
#define jml_maks 20
#define Front(Q) (Q)->Front 
#define Rear(Q) (Q)->Rear
#define Items(Q) (Q)->Items

typedef struct{
    int Front;
    int Items[jml_maks+1];
    int Rear;
}Queue;

void initQueue(Queue * Q);

boolean isEmpty(Queue * Q);

boolean isfull(Queue * Q);

void endQueue(Queue * Q, int X);

int deQueue(Queue * Q);

void display(Queue * Q);

int peek(Queue * Q);




#endif  