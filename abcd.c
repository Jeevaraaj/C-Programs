#include<stdio.h>

void main(){
    char arr[]="aabbbcccccccccc";
    int i=0,count=1;
    while (arr[i] != '\0')
    {
      char character = arr[i];
      if (arr[i] == arr[i+1])
      {
        count++;
      }else
      {
        printf("%c",character);
        if (count != 1)
        {
            printf("%d",count);
        }
        count=1;
      }
      i++;
    }
}