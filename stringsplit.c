#include<stdio.h>
#include<string.h>
#include<ctype.h>

void sort(char*);

void main(){
    char instr[] = "J1E2E2V3A4";
    char output[10];
    char inoutput[10];
    int charpos=0,intpos=0;
    int len = strlen(instr);
    for (int i = 0; i < len ; i++)
    {
        if (isalpha(instr[i]))
        {
            output[charpos++]=instr[i];
        }else if (isdigit(instr[i]))
        {
            inoutput[intpos++]=instr[i];
        }   
    }
    output[charpos]='\0';
    inoutput[intpos]='\0';
   
    sort(output);
    sort(inoutput);
}

void sort(char in[]){
    char temp;
    for (int i = 0; i < strlen(in); i++)
    {
        for (int j = i+1; j < strlen(in); j++)
        {
            if (in[i]>in[j])
            {
              temp=in[i];
              in[i]=in[j];
              in[j]=temp;  
            }
        }
    }
    printf("%s %d ",in,strlen(in));
}