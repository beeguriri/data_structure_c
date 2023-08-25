#include <stdio.h>
#include "ALGraphDFS.h"

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

    DFSShowGraphVertexInfo(&graph, A); printf("\n");
    DFSShowGraphVertexInfo(&graph, C); printf("\n");
    DFSShowGraphVertexInfo(&graph, E); printf("\n");
    DFSShowGraphVertexInfo(&graph, G); printf("\n");

    GraphDestroy(&graph);
    
    return 0;
}