#include<stdio.h>


void mergearr(int*,int*,int,int);
void main(){
    int array1[10] = {1,3,5,7,9,14,18,19};
    int array2[10] = {2,4,6,8,10,12,20,23,50};
    int len = sizeof(array1)/sizeof(array1[0]);
    int len2 = sizeof(array2)/sizeof(array2[0]);
    mergearr(array1,array2,len,len2);
}

void mergearr(int input1[],int input2[],int len,int len2){
    int outputarray[20],pos=0,pos2=1;

    for (int i = 0; i <= len; i++)
    {
            outputarray[pos] = input1[i];
            pos+=2;
    }
    for (int j = 0; j < len2 ; j++)
    {   
        outputarray[pos2] = input2[j];
        if (outputarray[pos2+1] != 0)
        {
               pos2+=2;
        }
        else{
            pos2++; 
        }
    }
    for (int k = 0; outputarray[k] != 0; k++)
    {
        printf(" %d ",outputarray[k]);
    }
}