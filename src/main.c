#include <stdio.h>
#include <stdlib.h>
#include "./Graph/List/AdjListGraph.h"
#include "./Queue/Queue.h"

void BFS(ALGraph *G, int v);

int main()
{
    ALGraph G;
    if(input(&G) == -1){
        printf("Error Not have this vetex Error\n");
    }
    BFS(&G, 0);
    // output(&G);
    printf("%d\n",freeALGraph(&G));
    return 0;
}

int visible[MVNum];
void BFS(ALGraph *G, int v)
{
    Queue Q;
    QueueNode Qn;
    initQueue(&Q);
    EnQueue(&Q, &(G->vertices[v].data));
    printf("EnQueue: %c\n", G->vertices[v].data);
    visible[v] = 1;

    printf("I am here!\n");
    ArcNode*p = G->vertices[v].firstarc;
    while(!IsEmpty(&Q))
    {
        OutQueue(&Q, &Qn);
        printf("OutQueue: %c\n", Qn);
        while (p)
        {
            if (!visible[p->adjvex]){
                EnQueue(&Q, &(G->vertices[p->adjvex].data));
                printf("EnQueue: %c\n", G->vertices[p->adjvex].data);
                visible[p->adjvex] = 1;
            }
            p = p->nextarc;
        }
        GetTop(&Q, &Qn);
        int location = LocateVex(G, Qn);
        p = G->vertices[location].firstarc;
    }
}