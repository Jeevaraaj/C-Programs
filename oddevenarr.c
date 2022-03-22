
#include<stdio.h>

void main()
{
    int array[10],i,j,temp,odd[10]={},even[10]={},o=0,e=0;
    printf("Enter 5 array elements\n");
    
    // getting input from user and grouping them into odd and even arrays
    
    for (i=0;i<5;i++)
    {
        scanf("%d",&array[i]);
        if((array[i]%2)==0)
        {
            even[e]=array[i];
            e++;
        }
        else
        {
           odd[o]=array[i]; 
           o++;
        }
    
    }
    for(i=0;i<e;i++)
    {
        for(j=i+1;j<e;j++)
        {
            if(even[i]>even[j])
            {
                temp=even[j];
                even[j]=even[i];
                even[i]=temp;
            }
        }
       
    }
    for(i=0;i<o;i++)
    {
        for(j=i+1;j<o;j++)
        {
            if(odd[i]<odd[j])
            {
                temp=odd[j];
                odd[j]=odd[i];
                odd[i]=temp;
            }
        }
        
    }
    e=0;
    o=0;
    
    for(i=0;i<10;i++)
    {
        if (i%2 == 0)
        {
            array[i]=odd[o];
            o++; 
        }else
        {
              array[i]=even[e];
              e++;
        }
    }
    
    printf("\nthe final answer is \n");

    for (i=0;i<10;i++)
    {
        printf("%d\t",array[i]);
    }
}