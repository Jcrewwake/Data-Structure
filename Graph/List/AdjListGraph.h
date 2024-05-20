#ifndef __ADJ_LIST_GRAPH_H__
#define __ADJ_LIST_GRAPH_H__

#define DEBUG
#define MVNum   100


typedef char VerTexType;
typedef int OtherInfo;

typedef struct ArcNode{
    int adjvex;
    struct ArcNode * nextarc;
    OtherInfo info;
}ArcNode;

typedef struct VNode{
    VerTexType  data;
    ArcNode*    firstarc;
}VNode, AdjList[MVNum];

typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
}ALGraph;



int LocateVex(ALGraph* G, VerTexType v);
int input(ALGraph* G);
void output(ALGraph* G);
int freeALGraph(ALGraph* G);

void DFS(ALGraph* G, int v);

#endif