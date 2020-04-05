//
// Created by Denisa on 4/4/2020.
//

#include "graphTraversals.h"


void bfsMatrix(FILE *output, int startNode, int noOfVertices, int **adjMatrix) {
    fprintf(output, "\nBFS for adjacency matrix started:\n");
    int v, w;
    int *visited = initializeVisitedArray(noOfVertices);

    Queue traversalQueue = createQueue();
    enQueue(&traversalQueue, startNode);
    visited[startNode] = VISITED;
    fprintf(output, "%c ", startNode + 'A');

    while (!isEmptyQueue(&traversalQueue)) {
        v = traversalQueue.first->data;
        deQueue(&traversalQueue);

        int noOfNeighbours = getNumberOfNeighboursOfVertex(noOfVertices, adjMatrix, v);
        int *neighbours = getAllNeighboursOfVertex(noOfVertices, adjMatrix, v);
        for (int i = 0; i < noOfNeighbours; i++) {
            w = neighbours[i];
            if (visited[w] == UNVISITED) {
                fprintf(output, "%c ", w + 'A');
                enQueue(&traversalQueue, w);
                visited[w] = VISITED;
            }
        }
    }
    fprintf(output, "\nBFS for adjacency matrix ended.\n");
}

void bfsList(FILE *output, int startNode, int noOfVertices, List *adjList) {
    fprintf(output, "\nBFS for adjacency list started:\n");
    int v, w;
    int *visited = initializeVisitedArray(noOfVertices);

    Queue traversalQueue = createQueue();
    enQueue(&traversalQueue, startNode);
    visited[startNode] = VISITED;
    fprintf(output, "%c ", startNode + 'A');
    while (!isEmptyQueue(&traversalQueue)) {
        v = traversalQueue.first->data;
        deQueue(&traversalQueue);

        int noOfNeighbours = adjList[v].noOfNodes;
        int *neighbours = adjList[v].first->neighbours;
        for (int j = 0; j < noOfNeighbours; j++) {
            w = neighbours[j];
            if (visited[w] == UNVISITED) {
                fprintf(output, "%c ", 'A' + w);
                enQueue(&traversalQueue, w);
                visited[w] = VISITED;
            }
        }
    }
    fprintf(output, "\nBFS for adjacency list ended.\n");
}

int *initializeVisitedArray(int noOfVertices) {
    int *visited = (int *) malloc(noOfVertices * sizeof(int));
    for (int i = 0; i < noOfVertices; i++) {
        *(visited + i) = UNVISITED;
    }
    return visited;
}

void dfsRecMatrix(FILE *output, int v, int *visited, int noOfVertices, int **adjMatrix) {
    visited[v] = VISITED;
    int noOfNeighbours = getNumberOfNeighboursOfVertex(noOfVertices, adjMatrix, v);
    int *neighbours = getAllNeighboursOfVertex(noOfVertices, adjMatrix, v);
    fprintf(output, "%c ", v + 'A');
    for (int i = 0; i < noOfNeighbours; i++) {
        int w = neighbours[i];
        if (visited[w] == UNVISITED) {
            dfsRecMatrix(output, w, visited, noOfVertices, adjMatrix);
        }
    }
}

void dfsRecUtilityMatrix(FILE *output, int startNode, int noOfVertices, int **adjMatrix) {
    fprintf(output, "\nDFS recursive for adjacency matrix started:\n");
    int *visited = initializeVisitedArray(noOfVertices);
    dfsRecMatrix(output, startNode, visited, noOfVertices, adjMatrix);
    fprintf(output, "\nDFS recursive for adjacency matrix ended.\n\n");
}

void dfsRecList(FILE *output, int v, int *visited, int noOfVertices, List *adjList) {
    visited[v] = VISITED;
    int noOfNeighbours = adjList[v].noOfNodes;
    int *neighbours = adjList[v].first->neighbours;
    fprintf(output, "%c ", v + 'A');
    for (int i = 0; i < noOfNeighbours; i++) {
        int w = neighbours[i];
        if (visited[w] == UNVISITED) {
            dfsRecList(output, w, visited, noOfVertices, adjList);
        }
    }
}

void dfsRecUtilityList(FILE *output, int startNode, int noOfVertices, List *adjList) {
    fprintf(output, "\nDFS recursive for adjacency list started:\n");
    int *visited = initializeVisitedArray(noOfVertices);
    dfsRecList(output, startNode, visited, noOfVertices, adjList);
    fprintf(output, "\nDFS recursive for adjacency list ended.\n");
}