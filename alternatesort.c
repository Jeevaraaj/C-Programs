#include<stdio.h> 
#include "sort.h"

void main(){
    int array[] = {10,7,3,6,5,2,1},index=0,*recptr,revindex,fwdindex=0;
    int len = sizeof(array)/sizeof(array[0]),n;
    n=len*2;
    int outputarray[n];
    revindex = len;
    recptr = sortDescending(array,len);
    for (int i = 0; i < (len*2); i++)
    {
        outputarray[index++] = array[fwdindex++];
        outputarray[index++] = array[--revindex];
    }
    for (int j = 0; j < (len*2); j++)
    {
        printf("%d ",outputarray[j]);
    }
}