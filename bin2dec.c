#include<stdio.h>
#include<math.h>

int bin2dec(int temp);

void main(){
    int bin;
    printf("enter a binary number\n");
    scanf("%d",&bin);
    printf("decimal of given binary is %d",bin2dec(bin));
}

int bin2dec(int temp){
    int digit,decval=0,i=0;
    while (1)
    {
        if (temp != 0)
        {
            digit = temp%10;
            temp = temp/10;
            decval += digit*pow(2,i);
            i++;
        }else{
             break;
        }
    }
}