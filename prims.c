#include<stdio.h>
int visited[10]={0},min,mincost=0,cost[10][10];
int i,j,a,b,u,v,n,ne=1;
int main()
{
    printf("Implementation of Prims's Algorithm");
    printf("Enter no. of nodes:");
    scanf("%d",&n);
    printf("Enter the cost Adjacency Matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    visited[1]=1;
    while(ne<n)
    {
        for(i=1,min=999;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    if(visited[i]==1)
                    {
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
        }
        if(visited[u]==0 || visited[v]==0)
        {
            printf("\nEdge %d:{%d %d) cost: %d",ne++,a,b,min);
            mincost+=min;
            visited[b]=1;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("\nMinimum cost =%d",mincost);
    return 0;
}
