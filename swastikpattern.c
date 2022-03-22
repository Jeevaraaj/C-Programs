#include<stdio.h>

void main(){
    int n=5;
    int mid =(n/2);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i==mid) || (j==mid))
            {
                printf("*");
            }
            else
            {
                printf("");
            }            
        }
        printf("\n");
    }
    
}
