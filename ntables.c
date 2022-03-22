#include<stdio.h>

void printtables(int);
void main(){
    int num;
    printf("Enter number to print tables\n");
    scanf("%d",&num);
    printtables(num);
}

void printtables(int n){
    for (int i = 1; i <= n; i++)
    {
        printf("\n\n%d \t table\n\n",i);
        for (int j = 1; j <= 10; j++)
        {
            printf("%d x %d = %d\n",j,i,(j*i));
        }
        
    }
    
}