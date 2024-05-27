#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "../Graph/List/AdjListGraph.h"

#define MaxNode 100
#define TRUE    1
#define FALSE   0
#define FULL    5
#define OK      1
#define EMPTY   0

typedef VerTexType QueueNode;
typedef unsigned char PointNum;
typedef unsigned char Status;

typedef struct Queue
{
    QueueNode queueList[MaxNode];
    PointNum first, rear;
}Queue;


void initQueue(Queue* Q);
Status EnQueue(Queue* const Q, const QueueNode* const Node);
Status OutQueue(Queue* const Q, QueueNode* const OutNode);
Status GetTop(const Queue* const Q, QueueNode* const FirstNode);
Status IsEmpty(const Queue* const Q);


#endif