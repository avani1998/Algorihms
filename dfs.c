#include<stdio.h>
int count=0;
void dfs(int visited[20],int source,int n,int a[20][20])
{
    int v;
    count++;
    visited[source]=count;
    for(v=1;v<=n;v++)
    {
        if(a[source][v]==1 && visited[v]==0)
            {
                dfs(visited,v,n,a);
            }
    }
}
void main()
{
    int i,j,visited[20],a[20][20],source,n,visitorder[20];
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the source node\n");
    scanf("%d",&source);
    for(i=1;i<=n;i++)
    visited[i]=0;
    dfs(visited,source,n,a);
    for(i=1;i<=n;i++)
    visitorder[visited[i]]=i;
    printf("The bfs traversal is\n");
    for(i=1;i<=n;i++)
    printf("%c\t",visitorder[i]+64);
}
