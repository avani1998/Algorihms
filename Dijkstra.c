#include<stdio.h>
void dijkstra(int source,int n,int cost[20][20],int visited[20],int d[20])
{
    int i,j,w,u,min;
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
                {
                    d[w]=cost[u][w]+d[u];
                }
            }
        }
    }
}

void main()
{
    int source,d[20],visited[20],cost[20][20],n;int i,j;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter the source\n ");
    scanf("%d",&source);
    printf("Enter the cost matrix \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    dijkstra(source,n,cost,visited,d);
    for(i=1;i<=n;i++)
    {
        if(i!=source)
        {
            printf("Shortest path from %d to %d is %d\n",source,i,d[i]);
        }
    }
}
