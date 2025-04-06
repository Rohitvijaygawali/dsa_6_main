#include <stdio.h>
#include <stdlib.h>

void display(int adj[][100], int v)
{
    printf("Adjacency matrix:\n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

void in_degree(int adj[][100], int v)
{
    printf("Indegree of vertices:\n");
    for (int i = 0; i < v; i++)
    {
        int indegree = 0;
        for (int j = 0; j < v; j++)
        {
            if (adj[j][i] == 1)
            {
                indegree++;
            }
        }
        printf("%d -> %d\n", i, indegree);
    }
}

void list(int adj[][100], int v)
{
    printf("Adjacency list:\n");
    for (int i = 0; i < v; i++)
    {
        printf("%d:", i);
        for (int j = 0; j < v; j++)
        {
            if (adj[i][j] == 1)
            {
                printf(" %d ->", j);
            }
        }
        printf(" NULL\n");
    }
}

void main()
{
    int adj[100][100] = {0}; // Initialize adjacency matrix to zero
    int v, e;

    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter edges in the format of u v:\n");
    for (int i = 0; i < e; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    display(adj, v);
    in_degree(adj, v);
    list(adj, v);

}