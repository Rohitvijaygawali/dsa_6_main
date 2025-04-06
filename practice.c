#include<stdio.h>


#define max 10

int adj[max][max]={0};
int V;

int min_dis(int dist[],int sptset[])
{
    int min=max,min_index;
    for(int i=0;i<V;i++)
    {
        if(sptset[i]==0 && dist[i]<=max)
        {
            min=dist[i];
            min_index=i;
        }
    }
    return min_index;
}

void dijkart(int start)
{
    int dist[V];
    int sptset[V];

    // initilaze shortest path
    for(int i=0;i<V;i++)
    {
        dist[i]=max;
        sptset[i]=0;
    }

    dist[start]=0;

    // main loop
    for(int c=0;c<V;c++)
    {
        int u=min_dist(dist,sptset);
        sptset[u]=1;

        for(int v=0;v<V;v++)
        {
        if(!sptset[v] && adj[u][v] && dist[u]!=max && dist[u]+adj[u][v]<dist[v])
        {
            dist[u]=dist[v]+adj[u][v];

        }
        }


    }
    printf("\nShortest distances from source vertex %d:\n", start);
          for (int i = 0; i < V; i++) {
              printf("Vertex %d -> Distance: %d\n", i, dist[i]);
          }
}



void main()
{
    int e,start;
      printf("vertices\t");
      scanf("%d",&V);
      printf("edges:\t");
      scanf("%d",&e);

      printf("enter thw data\n");
      for(int i=0;i<e;i++)
      {
        int u,v,weigth;
        scanf("%d%d%d",&u,&v,&weigth);
        adj[u][v]=weigth;
        adj[v][u]=weigth;
      }

      printf("enter the start vertex\n");
      scanf("%d",&start);
      dijkart(start);
}