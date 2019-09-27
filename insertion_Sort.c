#include<stdio.h>
int main()
{
    int n,a[40],i,j,temp;
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Enter array:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<n;i++)
    {
        int val=a[i];
        j=i-1;
        while(val<a[j] && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=val;
    }
    printf("Sorted Array:");
    for(i=0;i<n;i++)
        printf("%d  ",a[i]);
    return 0;
}
