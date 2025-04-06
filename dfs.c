#include <stdio.h>
#include <stdlib.h>
#define max 100

int adjmatrix[max][max] = {0};
int visited[max] = {0};

void dfs(int v, int start_vertex) {
    visited[start_vertex] = 1;
    printf("%d ", start_vertex);  // Print the visited vertex during DFS

    for (int i = 0; i < v; i++) {
        if (adjmatrix[start_vertex][i] == 1 && !visited[i]) {
            dfs(v, i);  // Recursive call
        }
    }
}

int main() {
    int v, e, start_vertex;

    printf("Enter number of vertices (v): ");
    scanf("%d", &v);

    printf("Enter number of edges (e): ");
    scanf("%d", &e);

    printf("Enter the edges (start_vertex end_vertex):\n");
    for (int i = 0; i < e; i++) {
        int s, en;
        scanf("%d %d", &s, &en);
        adjmatrix[s][en] = 1;
        adjmatrix[en][s] = 1;  // For undirected graph
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start_vertex);

    printf("DFS Traversal: ");
    dfs(v, start_vertex);
    printf("\n");

    return 0;
}
