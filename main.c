#include <stdio.h>
#include "./Graph/List/AdjListGraph.h"
#include "./Queue/Queue.h"

int main()
{
    Queue Q;
    ALGraph G;
    if(input(&G) == -1){
        printf("Error Not have this vetex Error\n");
    }
    DFS(&G, 0);
    // output(&G);
    printf("%d\n",freeALGraph(&G));
    return 0;
}