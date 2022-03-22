#include<stdio.h>

void main(){
    int inputarray[] = {1,2,4,5,2,4,6,8};
    int len = sizeof(inputarray)/sizeof(inputarray[0]),sameaccur[10];
    int accurances[10],count=0,accuranceslen=10,index=0;
    for (int i = 1; i<=accuranceslen ; i++)//count accurances starts
    {
        for (int j = 0; j < len; j++)
        {
            if (i == inputarray[j])
            {
                count++;
            }
        }
        accurances[i-1]=count;
        count=0;
    }//count accurances end
    for (int i = 1; i<=accuranceslen ; i++)//validate same accurances start
    {
        for (int j = i; j < accuranceslen; j++)
        {
            if ((accurances[i] == accurances[j]) && (accurances[i] != 0 && accurances[j] != 0))
            {
                accurances[i] = -1;
                accurances[j] = -1;
                sameaccur[index++] = i;
            }
        }
    }//validate same accurances end
    for (int k = 0; k < 10; k++)
    {
        printf("%d\n",accurances[k]);
    }
    printf("\end");
    for (int l = 0; sameaccur[l] != 0; l++)
    {
        printf("%d\n",sameaccur[l]);
    }
      
}
