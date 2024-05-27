#ifndef __ADJ_MATRIX_GRAPH_H__
#define __ADJ_MATRIX_GRAPH_H__

#define MaxInt  32767
#define MVNum   100
#define DEBUG
typedef char VerTexType;
typedef int ArcType;

typedef struct{
    VerTexType  vexs[MVNum];
    ArcType     arcs[MVNum][MVNum];
    int vexnum, arcnum;
}AMGraph;

int LocateVex(AMGraph* G, VerTexType v);
int input(AMGraph* G);
void output(AMGraph* G);

void DFS(AMGraph G, int v);
#endif