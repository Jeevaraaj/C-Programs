
#include<stdio.h>

void main(){
    int a,b,res=1;
    printf("Enter number \n");
    scanf("%d",&a);
    printf("Enter power number \n");
    scanf("%d",&b);
    for (b; b > 0; b--){
        res=res*a;
    }
    printf("power of given number is %d\n\n\n",res);
}