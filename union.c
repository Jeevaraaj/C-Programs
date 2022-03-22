#include<stdio.h>
int printunion(int arr1[],int arr2[],int m,int n);
{
    int i=0,j=0;
    while(i<m&&i<n)
    {
        if(arr1[i]<arr[j])
        {
        printf("%d",arr1[i]);
        i++;
        }
        else if(arr[j]<arr[i])
        {
        printf("%d",arr2[j]);
        j++;
        }
        else
        {
            printf("%d",arr2[j++]);
            i++;
        
        }
    }
    
    while(i<m)
    {
    printf("%d",arr1[i++]);
    }
    while(j<n)
    {
    printf("%d",arr2[j++]);
    }
}
void main()
{
    int arr1[]={1,2,4,5,6};
    int arr2[]={2,3,5,7};
    int m,n;
    m=sizeof(arr1)/sizeof(arr1[0]);
    n=sizeof(arr2)/sizeof(arr2[0]);
    printunion(arr1,arr2,m,n);
}

    


