#include <stdio.h>
#define MAX_VERTICES 10

int adjMatrix[MAX_VERTICES][MAX_VERTICES];
int numVertices;

void initGraph(int vertices) {
    numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

// For an undirected graph, set both (u, v) and (v, u)
void addEdge(int u, int v) {
    if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; 
    }
}

void printMatrix() {
    printf("Adjacency Matrix:\n  ");
    for (int i = 0; i < numVertices; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < numVertices; i++) {
        printf("%d ", i);
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initGraph(4);

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 3);

    printMatrix();

    return 0;
}