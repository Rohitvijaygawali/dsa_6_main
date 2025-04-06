#include <stdio.h>
      #include <limits.h>
      
      #define MAX_VERTICES 10
      
      // Function to find the vertex with the minimum distance value
      int minDistance(int dist[], int sptSet[], int V) {
          int min = INT_MAX, min_index;
          
          for (int v = 0; v < V; v++) {
              if (sptSet[v] == 0 && dist[v] <= min) {
                  min = dist[v];
                  min_index = v;
              }
          }
          
          return min_index;
      }
      
      // Function to implement Dijkstra's algorithm
      void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src, int V) {
          int dist[V];
          int sptSet[V];
          
          // Initialize distances and the shortest path set
          for (int i = 0; i < V; i++) {
              dist[i] = INT_MAX;
              sptSet[i] = 0;
          }
          
          dist[src] = 0;
          
          // Dijkstra's main loop
          for (int count = 0; count < V - 1; count++) {
              int u = minDistance(dist, sptSet, V);
              sptSet[u] = 1;
              
              for (int v = 0; v < V; v++) {
                  if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                      dist[v] = dist[u] + graph[u][v];
                  }
              }
          }
          
          // Print the results
          printf("\nShortest distances from source vertex %d:\n", src);
          for (int i = 0; i < V; i++) {
              printf("Vertex %d -> Distance: %d\n", i, dist[i]);
          }
      }
      
      int main() {
          int V, E, src;
          
          // Input the number of vertices and edges
          printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
          scanf("%d", &V);
          
          
          int graph[MAX_VERTICES][MAX_VERTICES];
          
          // Initialize graph with 0 (no edges)
          for (int i = 0; i < V; i++) {
              for (int j = 0; j < V; j++) {
                  graph[i][j] = 0;
              }
          }
          
          // Input the number of edges
          printf("Enter the number of edges: ");
          scanf("%d", &E);
      
          // Input the edges with their weights
          printf("Enter the edges (u v weight):\n");
          for (int i = 0; i < E; i++) {
              int u, v, weight;
              scanf("%d %d %d", &u, &v, &weight);
              graph[u][v] = weight;
              graph[v][u] = weight;  // For undirected graph
          }
      
          // Input the source vertex
          printf("Enter the source vertex: ");
          scanf("%d", &src);
      
          // Check if source is valid
          if (src < 0 || src >= V) {
              printf("Error: Source vertex out of range.\n");
              return 1;
          }
      
          // Run Dijkstra's algorithm
          dijkstra(graph, src, V);
          
          return 0;
      }
      