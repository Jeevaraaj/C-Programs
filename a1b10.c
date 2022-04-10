#include<stdio.h>
#include<ctype.h>
#include<string.h>

void printoutput(char,int);

void main(){
    char arr[]="a10b12c20";
    int count=0;
    int len = strlen(arr);
    for (int i = 0;i<len; i++)
    {
        if (isdigit(arr[i]))
        {
            char printchar = arr[i-1];
            if (isdigit(arr[i+1]))
            {
                count = ((arr[i]-'0')*10)+(arr[i+1]-'0');
                printoutput(printchar,count);
                i+=2;
            }else
            {
                count = arr[i]-'0';
                printoutput(printchar,count);   
            }
        }
    }
}

void printoutput(char printchar,int count){
    for (int j = 0; j < count; j++)
    {
            printf("%c",printchar);
    }
}