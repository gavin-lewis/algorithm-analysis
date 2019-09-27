#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[100],b[100];
	printf("Enter text string:");
	scanf("%s",a);
	printf("Enter the pattern string:");
	scanf("%s",b);
	int la=strlen(a);
	int lb=strlen(b);
	int d=100,p=0,t=0,h=1,i,j,mod=13;
	for(i=0;i<lb-1;i++)
		h=(d*h)%mod;
	for(i=0;i<lb;i++)
	{
		p=(d*p+b[i])%mod;
		t=(d*t+a[i])%mod;
	}
	for(i=0;i<=(la-lb);i++)
	{
		if(p==t)
		{
			for(j=0;j<lb;j++)
			{
				if(a[i+j]!=b[j])
					break;
			}
			if(j==lb)
				printf("Parttern found at %d\n",i+1);
		}
		if(i<(la-lb))
		{
			t=(d*(t-a[i]*h)+a[i+lb])%mod;
			if(t<0)
				t=(t+mod);
		}
	}
	return 0;
}
