#include <stdio.h>
#include <stdlib.h>
#include "AdjListGraph.h"

int input(ALGraph* G)
{
    printf("please input vetex num: ");
    scanf("%d", &G->vexnum);
    getchar();
    printf("please input arc num: ");
    scanf("%d", &G->arcnum);
    getchar();

#ifdef DEBUG
    printf("input vetex num: %d\n", G->vexnum);
    printf("input arc num: %d\n", G->arcnum);
#endif

    for (int i = 0; i < G->vexnum; i++)
    {   
        printf("please input vetex[%d]: ", i);
        scanf("%c", &G->vertices[i].data);
        getchar();  //use eat '\n'
        printf("input vetex[%d]: %c\n", i, G->vertices[i].data);

        G->vertices[i].firstarc = NULL;
    }
    for (int i = 0; i < G->arcnum; i++)
    {
        VerTexType vetex1, vetex2;
        printf("please input vetex1:");
        scanf("%c", &vetex1);
        getchar();  //use eat '\n'
        printf("please input vetex2:");
        scanf("%c", &vetex2);
        getchar();  //use eat '\n'
        printf("please input vetex1: %c  vetex2: %c  value:", vetex1, vetex2);
        int row, col;
        row = LocateVex(G, vetex1);
        col = LocateVex(G, vetex2);
        if (row == -1 || col == -1){
            return -1;
        }

        OtherInfo a;
        scanf("%d", &a);
        getchar();  //use eat '\n'

        ArcNode* new_Node = (ArcNode*)malloc(sizeof(ArcNode));
        new_Node->adjvex = col;
        new_Node->info = a;
        ArcNode*p = G->vertices[row].firstarc;
        new_Node->nextarc = p;
        G->vertices[row].firstarc = new_Node;
        printf("input arcs value: %d\n", a);
    }
    return 0;
}

void output(ALGraph* G)
{
    for (int i = 0; i < G->vexnum; i++)
    {
        printf("%c ", G->vertices[i].data);
    }
    printf("\n");

    for (int i = 0; i < G->vexnum; i++)
    {
        ArcNode* p = G->vertices[i].firstarc;
        while(p != NULL)
        {
            printf("%c %c value: %d\n", G->vertices[i].data, G->vertices[p->adjvex].data, p->info);
            p = p->nextarc;
        }
    }
}

int freeALGraph(ALGraph* G)
{
    int count = 0;
    for(int i = 0; i < G->vexnum; i++)
    {
        ArcNode* p = G->vertices[i].firstarc;
        while (p)
        {
            ArcNode* next = p->nextarc;
            free(p);
            count++;
            p = next;   
        }
        G->vertices[i].firstarc = NULL;
    }
    return count;
}

int LocateVex(ALGraph* G, VerTexType v)
{
    int index;
    for (index = 0; index < G->vexnum && G->vertices[index].data != v;index++);
    if (index == G->vexnum)
        index = -1;
    return index;
}


// int visible[MVNum];
// void DFS(ALGraph* G, int v)
// {
//     printf("vertex[%d]:%c\n", v, G->vertices[v].data);
//     visible[v] = 1;
//     ArcNode* p = G->vertices[v].firstarc;
//     while(p)
//     {
//         if(visible[p->adjvex] == 0)
//         {
//             DFS(G, p->adjvex);
//         }
//         p = p->nextarc;
//     }
// }