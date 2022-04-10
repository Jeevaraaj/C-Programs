#include<stdio.h>
#include<string.h>

struct tense{
    char word[10];
};

char* calculatewordones(struct tense ones[],int number);
char calculatewordtens(struct tense ones[],struct tense tens[],int number);

void main(){
    
    struct tense ones[] = {{"one"},{"two"},{"three"},{"four"},{"five"},{"six"},{"seven"},{"eight"},{"nine"},{"ten"},{"eleven"},{"twelve"},{"thirteen"},{"fourteen"},{"fifteen"},{"sixteen"},{"seventeen"},{"eighteen"},{"nineteen"}};
    struct tense tens[] = {{""},{"twenty"},{"thirty"},{"fourty"},{"fifty"},{"sixty"},{"seventy"},{"eighty"},{"ninety"}};
   
    int input=11101,temp;
    char* returnstring;
    temp = input/1000;
    if (temp < 20)
    {
        returnstring = calculatewordones(ones,temp);
        printf("%s thousand",returnstring);
    }else
    {
        calculatewordtens(ones,tens,temp);
        printf("thousand");  
    }

    temp = input%1000;
    temp = temp/100;
    if (temp>0)
    {
        returnstring = calculatewordones(ones,temp);
        printf(" %s hundred and",returnstring);
    }

    temp = input%1000;
    temp = temp%100;
    if (temp < 20)
    {
        returnstring = calculatewordones(ones,temp);
        printf(" %s ",returnstring);
    }else
    {
        calculatewordtens(ones,tens,temp);  
    }
}

char* calculatewordones(struct tense ones[],int number){
        return ones[number-1].word;   
}

char calculatewordtens(struct tense ones[],struct tense tens[],int number){
    int temp;
    char tensname[10],onesname[10];
    if (number > 0)
    {
        temp = number%10;
        strcpy(onesname,ones[temp-1].word);
        temp = number/10;
        strcpy(tensname,tens[temp-1].word);
        strcat(tensname,onesname);
        printf(" %s ",tensname);
    }
} 

