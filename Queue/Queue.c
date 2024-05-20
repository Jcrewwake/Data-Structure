#include <stdio.h>

#define MaxNode 100
#define FULL    5

typedef char QueueNode;

typedef struct Queue
{
    QueueNode queueList[MaxNode];
    unsigned char first, rear;
}Queue;

void initQueue(Queue* Q)
{
    Q->first = 0;
    Q->rear = 0;
}

unsigned char EnQueue(Queue* Q, QueueNode Node)
{
    if ((Q->rear + 1) % MaxNode == Q->first){
        return FULL;
    }
    Q->queueList[Q->rear] = Node;
    Q->rear++;
}
