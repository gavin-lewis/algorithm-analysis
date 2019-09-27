#include<stdio.h>
int i,j,n;;
void print(int a[])
{
    for(i=0;i<n;i++)
        printf("%d   ",a[i]);
    printf("\n");
}
void merge(int a[],int lb,int mid,int ub)
{
    int l=lb,r=mid+1;
    int temp[50],i=0;
    while(l<=mid && r<=ub)
    {
        if(a[l]>a[r])
        {
            temp[i]=a[r];
            r++;
        }
        else{
            temp[i]=a[l];
            l++;
        }
        i++;
    }
    while(l<=mid)
    {
        temp[i]=a[l];
        i++;l++;
    }
    while(r<=ub)
    {
        temp[i]=a[r];
        i++;r++;
    }
    for(i=0,j=lb;j<=ub;j++,i++)
        a[j]=temp[i];
    print(a);
}
void mergeSort(int a[],int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergeSort(a,lb,mid);
        mergeSort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}
int main()
{
    int a[40];
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Enter array:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    mergeSort(a,0,n-1);
}
