#include<stdio.h>
int ne=1,mincost=0;
void main()
{
    int cost[20][20],i,j,n,source,min,visited[20],a,b;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter the cost matrix\n");
    for (i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    {
       visited[i]=0;
    }
    printf("Enter the source\n");
    scanf("%d",&source);
    visited[source]=1;
    printf("The minimum spaning tree is\n");
    while(ne<n)
    {
        min=999;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    if(visited[i]==0)
                        continue;
                    else
                    {
                        min=cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }
        if(visited[a]==0||visited[b]==0)
        {
            printf("\n edge %d(%d->%d)=%d\n",ne++,a,b,min);
            mincost=mincost+min;
            visited[b]=1;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("Min cost is %d",mincost);
}
