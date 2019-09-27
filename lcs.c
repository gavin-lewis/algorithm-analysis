#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char h[50],v[50],b[50][50];
int c[50][50],m,n;
void print(int i,int j)
{
    if(i==0 || j==0)
        return;
    if(b[i][j]=='c')
    {
        print(i-1,j-1);
        printf("%c",v[i-1]);
    }
    else if(b[i][j]=='u')
    {
        print(i-1,j);
    }
    else
        print(i,j-1);

}
void lcs()
{
    m=strlen(v);
    n=strlen(h);
    int i,j;
    for(i=0;i<m;i++)
        c[i][0]=0;
    for(i=0;i<n;i++)
        c[0][i]=0;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(v[i-1]==h[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='c';
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]='u';
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]='l';
            }
        }
    }
    print(m,n);
}
int main()
{
    printf("Enter string 1:");
    scanf("%s",h);
    printf("Enter string 2:");
    scanf("%s",v);
    lcs();
    return 0;
}
