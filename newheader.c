#include<stdio.h>
#include "sort.h"

void main(){
    char str[] = "jeeva";
    char* str1;
    str1 = charsortAsc(str);
    printf("%s",str1);
    str1 = charsortDesc(str);
    printf("%s",str1);
    int array[] = {5,34,35,74,2,89,45,8,28};
    int len = sizeof(array)/sizeof(array[0]);
    int* ptr = sortAscending(array,len);
    for (int i = 0; i < len; i++)
    {
        printf("\n%d ",ptr[i]);
    }
    ptr = sortDescending(array,len);
    for (int i = 0; i < len; i++)
    {
        printf("\n%d ",ptr[i]);
    }
}