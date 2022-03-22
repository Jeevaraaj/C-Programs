#include<stdio.h>
#include<string.h>

void count_vowels(char*);

void main(){
    char input[] = "welcome to zoho corporation";
    count_vowels(input);
}

void count_vowels(char input[]){
    int acount=0,ecount=0,icount=0,ocount=0,ucount=0,len;
    len = strlen(input); 
    for (int i = 0; i < len ; i++)
    {
        if ((input[i] == 'a') || (input[i] == 'A'))
        {
            acount++;
        }
        if ((input[i] == 'e') || (input[i] == 'E'))
        {
            ecount++;
        }
        if ((input[i] == 'i') || (input[i] == 'I'))
        {
            icount++;
        }
        if ((input[i] == 'o') || (input[i] == 'O'))
        {
            ocount++;
        }
        if ((input[i] == 'u') || (input[i] == 'U'))
        {
            ucount++;
        }
    }
    printf("\n\"a\" count is %d\n\"e\" count is %d\n\"I\" count is %d\n\"o\" count is %d\n\"u\" count is %d\n",acount,ecount,icount,ocount,ucount);
}