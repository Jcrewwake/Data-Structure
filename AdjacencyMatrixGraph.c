#include <stdio.h>
#include <stdlib.h>

#define MaxInt  32767
#define MVNum   100
#define DEBUG
#define Test
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

int main()
{
    AMGraph* G = (AMGraph*)malloc(sizeof(AMGraph));
    if(input(G) == -1){
        printf("Error Not have this vetex Error\n");
    }
    output(G);

    free(G);
    G = NULL;
    return 0;
}

int input(AMGraph* G)
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
        scanf("%c", &G->vexs[i]);
        getchar();  //use eat '\n'
        printf("input vetex[%d]: %c\n", i, G->vexs[i]);
    }
    for (int i = 0; i < G->vexnum; i++)
    {
        for (int j = 0; j < G->vexnum; j++){
            G->arcs[i][j] = MaxInt;
        }
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

        int a;
        scanf("%d", &a);
        getchar();  //use eat '\n'
        G->arcs[row][col] = a;
        G->arcs[col][row] = G->arcs[row][col];
        printf("input arcs value: %d", G->arcs[row][col]);
    }
    return 0;
}

void output(AMGraph* G)
{
    for (int i = 0; i < G->vexnum; i++)
    {
        printf("%c ", G->vexs[i]);
    }
    printf("\n");

    for (int i = 0; i < G->vexnum; i++)
    {
        for(int j = 0; j < G->vexnum; j++)
        {
            if (G->arcs[i][j] != MaxInt)
                printf("%c %c value: %d\n", G->vexs[i], G->vexs[j], G->arcs[i][j]);
        }
    }
}

int LocateVex(AMGraph* G, VerTexType v)
{
    int index;
    for (index = 0; index < G->vexnum && G->vexs[index] != v;index++);
    if (index == G->vexnum)
        index = -1;
    return index;
}