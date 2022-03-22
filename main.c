#include <stdio.h>
#include <stdlib.h>

void main(){
    int a,b,i,res;

    printf("Enter Two numbers:");
    scanf("%d%d",&a,&b);

    for ( i = 2; i <= a && i<=b; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            res = i;
        }
    }
    printf("gcd of a given number %d and %d is %d",a,b,res);
}
