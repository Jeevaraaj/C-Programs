#include<stdio.h>

void split(int*);

void main(){
    int totalarr[]= {1,2,3,4,5,6,7,8,9};
    split(totalarr);
}

void split(int inputarr[]){
    int len,evenarr[20],oddarr[20],pos2=0,pos=0;
    len = sizeof(inputarr)/sizeof(inputarr[0]);
    for (int i = 0; i < len; i++)
    {
        if ((inputarr[i] % 2) == 0)
        {
            evenarr[pos] = inputarr[i];
            pos++;
        }else
        {
            oddarr[pos2] = inputarr[i];
            pos2++;
        }
    }
}