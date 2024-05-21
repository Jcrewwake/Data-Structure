#include <stdio.h>
#include "./Graph/List/AdjListGraph.h"
#include "./Queue/Queue.h"

void BFS(ALGraph *G, int v);

int main()
{
    ALGraph G;
    if(input(&G) == -1){
        printf("Error Not have this vetex Error\n");
    }
    DFS(&G, 0);
    // output(&G);
    printf("%d\n",freeALGraph(&G));
    return 0;
}

int visible[];
void BFS(ALGraph *G, int v)
{
    Queue Q;
    QueueNode Qn;
    initQueue(&Q);
    EnQueue(&Q, G->vertices[v].data);

    ArcNode*p = G->vertices[v].firstarc;
    while(!IsEmpty(&Q))
    {
        OutQueue(&Q, &Qn);
        printf("%c\n", Qn);
        while (p)
        {
            EnQueue(&Q, G->vertices[p->adjvex].data);
            p = p->nextarc;
        }
    }
}