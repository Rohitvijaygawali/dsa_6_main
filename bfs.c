#include <stdio.h>
#include <stdbool.h>
#define MAX 100

void bfs(int adjMatrix[MAX][MAX], int visited[MAX], int start, int vertices) {
    int queue[MAX], front = 0, rear = 0;
    
    // Enqueue the starting vertex and mark it as visited
    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (front < rear) {
        int current = queue[front++]; // Dequeue
        printf("%d ", current);

        // Visit all adjacent vertices
        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[current][i] == 1 && !visited[i]) {
                queue[rear++] = i; // Enqueue unvisited neighbor
                visited[i] = 1;    // Mark it as visited
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices, edges, startVertex;
    int adjMatrix[MAX][MAX] = {0};
    int visited[MAX] = {0};

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: start_vertex end_vertex):\n");
    for (int i = 0; i < edges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        adjMatrix[start][end] = 1; // For undirected graph, also set adjMatrix[end][start] = 1
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    bfs(adjMatrix, visited, startVertex, vertices);

    return 0;
}
