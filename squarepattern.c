#include<stdio.h>

void main(){
    int numrows=7;
    int mid = (numrows/2)+1;
    for (int i = 0; i < numrows; i++)
    {
        for (int j = 0; j < numrows; j++)
        {
            if ((i-j)==(mid-1) || (i+j)==(mid-1) || (j-i) == (mid-1) || (i+j)==(mid/2)+numrows)
            {
                printf("*");
            }else
            {
                printf(" ");
            }
        }  
        printf("\n"); 
    }
}