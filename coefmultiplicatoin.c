#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct equation
{
    //char symbol[10];
    int  coef[10];
    char var[10];
    int  power[10];
};

void store_structure(struct equation *equ,char* input,int pos);
void multiply(struct equation input[]);

void main(){
    struct equation equa[2];
    char eq1[]="9x+5y";
    char eq2[]="3x+4y";
    store_structure(equa,eq1,0);
    store_structure(equa,eq2,1);
    for (int i = 0; i < 2; i++)
    {
        printf("%d %c %d %d %c %d\n",equa[i].coef[0],equa[i].var[0],equa[i].power[0],equa[i].coef[1],equa[i].var[1],equa[i].power[1]);
    }
    multiply(equa);
}

void store_structure(struct equation *equ,char* input,int pos){
    int k=0;
    int len = strlen(input);
    for (int i = 0; input[i] != '\0';i++)
    {
        if (isalpha(input[i]))
        {
            equ[pos].var[k]=input[i];
            if (isdigit(input[i-1]))
            {
                equ[pos].coef[k]=(input[i-1]-48);
            }else
            {
                equ[pos].coef[k]=1;
            }
            if (input[i+1] == '^')
            {
                equ[pos].power[k]=input[i+2];
            }else
            {
                equ[pos].power[k]=1;
                k++;
            }   
        }
    }     
}

void multiply(struct equation input[])
{
    struct equation output;
    int i=0,j=0,k=0,l=1;
    while (1)
    {
        if(input[i].power[i]==)
        if (j<2)
        {
            output.coef[j++] = (input[i].coef[i]*input[l].coef[k++]);
        }else
        {
            break;
        }
    }
    printf("%d %d",output.coef[0],output.coef[1]);
}

