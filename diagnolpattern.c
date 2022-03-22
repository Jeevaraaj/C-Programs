#include<stdio.h>

void main(){
    int numrows=5,pv=1;
    for (int i = 0; i < numrows; i++)
    {
        for (int j = 0; j < numrows; j++)
        {
            if ((i-j) == 0)
            {
                printf("%d ",(pv*2));
                pv++;
            }else
            {
                printf("%d ",pv);
                pv++;
            }
        }
        printf("\n");
    }
    
}