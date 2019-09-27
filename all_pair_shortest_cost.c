#include<stdio.h>
int n,i,j;
void printarr(int g[][50])
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(g[i][j]==999)
                printf("$  ");
            else
                printf("%d  ",g[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}
void allpair(int g[][50])
{
    int k;
    for(k=0;k<n;k++)
    {
        printf("D(%d):\n",k);
        printarr(g);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if((g[i][k]+g[k][j])<(g[i][j]))
                {
                    g[i][j]=g[i][k]+g[k][j];
                }
            }
        }

    }
    printf("D(%d):\n",k);
    printarr(g);
}
int main()
{
    int g[50][50];
    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("Enter adjacency matrix with weights:");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&g[i][j]);
            if(i==j)
                g[i][j]=0;
        }
    }
    printarr(g);
    allpair(g);
}
