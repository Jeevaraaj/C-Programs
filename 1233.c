#include<stdio.h>

void main(){
    int num=7,pv=0,key=1;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            pv+=key;
            printf("%d ",pv);
        }
        key++;
        printf("\n");
    }
    
}