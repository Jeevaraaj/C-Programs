#include<stdio.h>

void print_pattern(int);

void main(){
    int n=4;
    print_pattern(n);
}

void print_pattern(int numrows){
    int k = 1;
    for (int i = 1; i <= numrows; i++)
    {
        for (int j = 1 ;j <= i; j++)
        {
            printf("%d ",k);
            k+=2;
        }
        printf("\n");
    }
    
}