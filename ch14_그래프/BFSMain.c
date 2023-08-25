#include <stdio.h>
#include "ALGraphBFS.h"

int main(void) {

    ALGraph graph;
    GraphInit(&graph, 7);

    AddEdge(&graph, A, B);
    AddEdge(&graph, A, D);
    AddEdge(&graph, B, C);
    AddEdge(&graph, D, C);
    AddEdge(&graph, D, E);
    AddEdge(&graph, E, F);
    AddEdge(&graph, E, G);

    showGraphEdgeInfo(&graph);

    BFSShowGraphVertexInfo(&graph, A); printf("\n");
    BFSShowGraphVertexInfo(&graph, C); printf("\n");
    BFSShowGraphVertexInfo(&graph, E); printf("\n");
    BFSShowGraphVertexInfo(&graph, G); printf("\n");

    GraphDestroy(&graph);
    
    return 0;
}