#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int n,i,j;
float w[50],p[50],pw[50],x[50],sack;
void swap(float *x,float *y)
{
    float temp=*x;
    *x=*y;
    *y=temp;
}
void knapsack()
{
    float u=sack;
    float profit=0;
    for(i=0;i<n;i++)
        x[i]=0.0;
    for(i=0;i<n;i++)
    {
        if(u<w[i])
            break;
        else
        {
            x[i]=1.0;
            profit+=p[i];
            u-=w[i];
        }
    }
    if(i<n)
        x[i]=u/w[i];
    profit+=(x[i]*p[i]);

    printf("Array X:");
    for(i=0;i<n;i++)
    {
        printf("\n%f  %f  %f      ",w[i],p[i],x[i]);
    }

    printf("\n%f",profit);
}
int main()
{
    printf("Enter number of elements");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter weight and profit of item %d:",i+1);
        scanf("%f %f",&w[i],&p[i]);
        //pw[i]=p[i]/w[i];
        //x[i]=0;
    }
    printf("Enter sack size:");
    scanf("%f",&sack);
    for(i=0;i<n;i++)
        pw[i]=p[i]/w[i];
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(pw[i]<pw[j])
            {
                swap(&pw[j],&pw[i]);
                swap(&p[j],&p[i]);
                swap(&w[j],&w[i]);
            }
        }
    }
    knapsack();
    return 0;
}
