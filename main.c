#include <stdio.h>
#include "AdjListGraph.h"

int main()
{
    ALGraph G;
    if(input(&G) == -1){
        printf("Error Not have this vetex Error\n");
    }
    output(&G);

    printf("freeALGraph:%d\n", freeALGraph(&G));
    return 0;
}