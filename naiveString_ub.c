#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char s[100],s1[100];
	int i,n,m,k;
	printf("Enter text:");
	scanf("%s",s);
	printf("Enter the string to be searched:");
	scanf("%s",s1);
	n=strlen(s);
	m=strlen(s1);
	k=0;
	for(i=0;i<n;i++)
	{
		if(s1[k]==s[i])
		{
			if(k<m)
				k++;
		}
		else
		{
			if(k>0)
                i--;
			k=0;
		}
		if(k==m)
		{
			printf("String found at %d\n",i);
		}
	}
	return 1;
}
