#include<stdio.h>
#include<string.h>

int* sortAscending(int*,int);
int* sortDescending(int*,int);
char* charsortAsc(char*);
char* charsortDesc(char*);

int* sortAscending(int input[],int length){
    int temp;
     for (int i = 0; i < length; i++)
    {
        for (int j = i+1; j < length; j++)
        {
            if (input[i]>input[j])
            {
              temp=input[i];
              input[i]=input[j];
              input[j]=temp;  
            }
        }
    }
    return input;
}
int* sortDescending(int input[],int length){
    int temp;
     for (int i = 0; i < length; i++)
    {
        for (int j = i+1; j < length; j++)
        {
            if (input[i]<input[j])
            {
              temp=input[i];
              input[i]=input[j];
              input[j]=temp;  
            }
        }
    }
    return input;
}
char* charsortAsc(char input[]){
    char temp;
    int len = strlen(input);
     for (int i = 0; i < len; i++)
    {
        for (int j = i+1; j < len; j++)
        {
            if (input[i]>input[j])
            {
              temp=input[i];
              input[i]=input[j];
              input[j]=temp;  
            }
        }
    }
    return input;
}
char* charsortDesc(char input[]){
    char temp;
    int len = strlen(input);
     for (int i = 0; i < len; i++)
    {
        for (int j = i+1; j < len; j++)
        {
            if (input[i]<input[j])
            {
              temp=input[i];
              input[i]=input[j];
              input[j]=temp;  
            }
        }
    }
    return input;
}