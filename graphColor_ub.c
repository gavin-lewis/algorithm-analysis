#include<stdio.h>
#include<stdlib.h>
int v,e,m,c,x[10],g[10][10];
int issafe(int k,int c)
{
	int i;
	for(i=1;i<=v;i++)
	{
		if(g[k][i]==1 && x[i]==c)
			return 0;
	}
	return 1;
}
void graphColor(int k)
{
	int i;
	for(c=1;c<=m;c++)
	{
		if(issafe(k,c))
		{
			x[k]=c;
			if(k+1<=v)
				graphColor(k+1);
			else
			{
				for(i=1;i<=v;i++)
				{
					printf("Vertex %d will have colour %d",i,x[i]);
					printf("\n");
				}
				exit(0);
			}
		}
	}
}
int main()
{
	int i,j,v1,v2,k;
	printf("Enter number of vertices:");
	scanf("%d",&v);
	printf("Enter number of edges:");
	scanf("%d",&e);
	m=v-1;
	for(j=1;j<=e;j++)
	{
		printf("Enter vertices between which the edges are present:");
		scanf("%d%d",&v1,&v2);
		g[v1][v2]=1;
		g[v2][v1]=1;
		if(v1==v2)
			g[v1][v2]=0;
	}
	for(i=0;i<v;i++)
		x[i]=0;
	graphColor(1);
	return 1;
}
