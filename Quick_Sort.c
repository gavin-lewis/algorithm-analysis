#include<stdio.h>
int n;
void printarr(int a[])
{
    for(int i=0;i<n;i++)
        printf("%d   ",a[i]);
    printf("\n");
}
int partition(int a[],int lb,int ub)
{
    int i,j,pivot,temp;
    pivot=lb;
    i=lb;
    j=ub;
    while(i<j)
    {
        while(a[i]<=a[pivot] && i<ub)
            i++;
        while(a[j]>a[pivot])
            j--;
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[pivot];
    a[pivot]=a[j];
    a[j]=temp;
    printarr(a);
    return j;
}
void quick(int a[],int lb,int ub)
{
    if(lb<ub)
    {
        int p=partition(a,lb,ub);
        quick(a,lb,p-1);
        quick(a,p+1,ub);
    }
}
int main()
{
    int a[50];
    printf("Enter number of elements:");
    scanf("%d", &n);
    printf("Enter the array:");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    quick(a,0,n-1);
    return 0;
}
