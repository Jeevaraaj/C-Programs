#include<stdio.h>

void main(){
    int numrows=5;
    for (int i = numrows; i > 0; i--)
    {     
        for (int space = numrows; space > i; space--)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("%d",i);
        }
        printf("\n");
    }
    
}