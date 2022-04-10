#include<stdio.h>
#include<string.h>

void calculate(int,int);

void main(){

    int number=11,base=16;
    calculate(number,base);
}

void calculate(int number,int base){
    char temp,res[10];
    int k =0;
        while (1)
        {
            if ((number == 1) || (number==0))
            {
                res[k++] = (number+'0');
                break;
            }
            temp = number%base;
            number = number/base;
            if ((temp+'0') > 9)
            {
                res[k++]=((temp+55));  
            }else
            {
                res[k++]=(temp+'0');
            } 
        }
        res[k]='\0';
        printf("%s",strrev(res));        
}
