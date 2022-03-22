#include<stdio.h>
#include<string.h>
#include<ctype.h>

char* OddCharOut(char name1[],char name2[]);
int countChar(char finname[]);
char flames(int length);

void main(){
    char name1[20]/*={'m','a','n','i','b','a','l','a','n'}*/,name2[20]/*={'k','a','l','e','e','s','w','a','r','i'}*/,res[20]; 
    int cntr;
    printf("welcome to FLAMES Calculator\n\n");
    printf("Enter Your Name\n");
    scanf("%s",name1);
    printf("Enter your crush name\n");
    scanf("%s",name2);
    strcpy(res,name2);
    cntr = countChar(OddCharOut (name1,name2));
    switch (flames(cntr))
    {
    case 'F':
        printf("%s is your Friend\n",res);
        break;
    case 'L':
        printf("%s is your Lover\n",res);
        break;
    case 'A':
        printf("you have affection on %s\n",res);
        break;
    case 'M':
        printf("you going to Marry %s\n",res);
        break;
    case 'E':
        printf("%s is your Enemy\n",res);
        break;
    case 'S':
        printf("%s is your sibbling\n",res);
        break;
    default:
        break;
    }

}

char* OddCharOut(char name1[],char name2[]){
    int count=0,len,len1;
    len = strlen(name1);
    len1 = strlen(name2);
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len1; j++)
        {
            if (name1[i] == name2[j])
            {
                name1[i]=1;
                name2[j]=1;
            }      
            
        }
    }
    strcat(name1,name2);
    return name1;
}
int countChar(char finname[]){
    int finlen = strlen(finname);
    int count=0;
    for (int k = 0; k < finlen; k++)
    {
        if (isalpha(finname[k]))
        {
            count++;
        }
        
    }
    return count;
}

char flames(int length){
    char flames[] = {'F','L','A','M','E','S','\0'};
    int delchar = 1;
    while (1)
    {
        int len = strlen(flames);
        if (len == 1)
        {
            break;
        }
        int delchar = length % len;
        for (int i = delchar; i < len ; i++)
        {
            flames[i] = flames[i+1];
        }
    }
    return flames[0];    
}