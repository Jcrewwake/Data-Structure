#include <stdio.h>
#include "Queue.h"

void initQueue(Queue* Q)
{
    Q->first = 0;
    Q->rear = 0;
}

Status EnQueue(Queue* const Q, const QueueNode* const Node)
{
    PointNum next_rear = (Q->rear + 1) % MaxNode;
    if (next_rear == Q->first){
        return FULL;
    }
    Q->rear = next_rear;
    Q->queueList[Q->rear] = *Node;
    return OK;
}

Status OutQueue(Queue* const Q, QueueNode* const OutNode)
{
    if (Q->rear == Q->first)
        return EMPTY;
    
    PointNum next_first = (Q->first + 1) % MaxNode;
    *OutNode = Q->queueList[next_first];
    Q->first = next_first;
    return OK;
}

Status GetTop(const Queue* const Q, QueueNode* const FirstNode)
{
    if (Q->rear == Q->first)
        return EMPTY;
    *FirstNode = Q->queueList[(Q->first + 1) % MaxNode];
    return OK;
}

Status IsEmpty(const Queue* const Q){
    if (Q->first == Q->rear)
        return TRUE;
    return FALSE;
}