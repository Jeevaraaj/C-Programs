#include<stdio.h>

void print(int,int*,int,int);
void main(){
    int numrows=5,evenkey=2,even=2,odd=3,oddkey=3;
    for (int i = 0; i < numrows; i++)
    {
       if ((i%2) == 0)
       {
           print(i,&even,numrows,evenkey);
       }else
       {
            print(i,&odd,numrows,oddkey);   
       }
    }
    
}

void print(int i,int* var,int numrows,int key){
    int j;
    for (j = 0; j <= i; j++){
        printf("%d ",*var);
        *var+=key;
    }
    for (int k = j; k < numrows; k++)
    {
        *var+=key;    
    }
     printf("\n");   
}