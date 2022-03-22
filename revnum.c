#include<stdio.h>

int revnum(int temp);

void main(){
    int input;
    printf("Enter a number to Reverse\n");
    scanf("%d",&input);
    printf("reverse of given number is \n");
    revnum(input);
}

int revnum(int temp){
    while (1)
    {
        if (temp != 0)
        {
            int digit = temp % 10;
            temp /= 10;
            printf("%d",digit);
        }else{
            printf("\n");
            break;
        }  
    }
}