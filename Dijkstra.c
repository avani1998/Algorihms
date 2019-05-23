#include<stdio.h>
void dijkstra(int cost[20][20],int visited[],int d[],int source,int n)
{
    int i,j,min,u,w;
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
        d[i]=cost[source][i];
    }
    visited[source]=1;
    d[source]=0;
    for(j=2;j<=n;j++)
    {
        min=999;
        for(i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                if(d[i]<min)
                {
                    min=d[i];
                    u=i;
                }
            }
        }
        visited[u]=1;
        for(w=1;w<=n;w++)
        {
            if(cost[u][w]!=999 && visited[w]==0)
            {
                if(d[w]>cost[u][w]+d[u])
                d[w]=cost[u][w]+d[u];
            }
        }
    }
}

void main()
{
    int i,j,cost[20][20],visited[20],d[20],n,source;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter the cost adjacency matrix\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&cost[i][j]);
    printf("Enter the source node\n");
    scanf("%d",&source);
    dijkstra(cost,visited,d,source,n);
    for(i=1;i<=n;i++)
        if(i!=source)
            printf("The distance from %d to %d is %d\n",source,i,d[i]);
}
