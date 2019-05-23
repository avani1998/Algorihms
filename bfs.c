#include<stdio.h>
int count=0;
void bfs(int a[20][20],int n,int visited[],int source)
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
                count++;
                visited[v]=count;
                queue[++r]=v;
            }
        }
    }
}
void main()
{
    int i,j,n,a[20][20],visited[20],source,visitorder[20];
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter adjacency matrix\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++)
        visited[i]=0;
    printf("Enter the source\n");
    scanf("%d",&source);
    bfs(a,n,visited,source);
    for(i=1;i<=n;i++)
        if(visited[i]==0)
            bfs(a,n,visited,i);
    for(i=1;i<=n;i++)
        visitorder[visited[i]]=i;
    printf("The bfs traversal is\n");
    for(i=1;i<=n;i++)
        printf("%c\t",visitorder[i]+64);
}
