#include<stdio.h>

void main(){
    int numrows=5,evennum=2,oddnum=1;
    for (int i = 1; i <= numrows; i++)
    {
        if ((i%2)==0)
        {
           for (int j = 0;j < i; j++)
            {
                printf("%d",evennum);
                evennum+=2;
            }
        }else
        {
            for (int k = 0;k < i; k++)
            {
                printf("%d",oddnum);
                oddnum+=2;
            }
        }
        printf("\n");        
    }
    
}