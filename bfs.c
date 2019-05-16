#include<stdio.h>
int count=0;
void bfs(int source,int n,int a[20][20],int visited[20])
{
    int queue[20],f,r,u,v;
    f=0;r=-1;
    count++;
    visited[source]=count;
    queue[++r]=source;
    while(f<=r)
    {
        u=queue[f++];
        for(v=1;v<=n;v++)
        {
            if(a[u][v]==1 && visited[v]==0)
            {
                queue[++r]=v;
                count++;
                visited[v]=count;
            }
        }
    }
}

void main()
{
    int source,a[20][20],visited[20];int n;int i,j;int visitorder[20];
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter the source\n");
    scanf("%d",&source);
    printf("Enter the adjacency matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    visited[i]=0;
    bfs(source,n,a,visited);
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            bfs(source,n,a,visited);
        }
    }
    for(i=0;i<=n;i++)
    {
        visitorder[visited[i]]=i;
    }
    printf("The bfs is\n");
    for(i=1;i<=n;i++)
    {
        printf("%c\t",visitorder[i]+64);
    }
}
