#include<stdio.h>
int main()
{
    int n,a[40],i,j,temp,min;
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Enter array:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
                min=j;
        }
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
    printf("Sorted Array:");
    for(i=0;i<n;i++)
        printf("%d  ",a[i]);
    return 0;
}

