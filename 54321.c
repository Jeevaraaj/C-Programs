#include<stdio.h>

void main(){
    int numrows=6;
    for (int i = numrows; i > 0; i--)
    {
        for (int j = numrows;j >= i; j--)
        {
            printf("%d",j);
        }
        printf("\n");
    }
    
}