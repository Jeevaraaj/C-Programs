#include<stdio.h>

void main(){
    int fn,sn,tn;
    printf("Enter three numbers with whitespace\n");
    scanf("%d%d%d",&fn,&sn,&tn);
    fn = fn+tn;
    tn = fn - tn;
    fn = fn - tn;
    printf("swapped number is %d %d %d",fn,sn,tn);
}