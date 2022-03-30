#include<stdio.h>
#include<string.h>

struct expression 
{
    struct term 
    {
        int coef;
        //int no_of_var;
        char var[10];
        int pow[10];
    }term[10];
};

//void do_multiply(struct expression *expr1,struct expression *expr2);


void main(){
    struct expression exp[2];
    exp[0].term[0].coef=-30;
    strcpy(exp[0].term[0].var,"x");
    exp[0].term[0].pow[0]=1;

    exp[0].term[1].coef=50;
    strcpy(exp[0].term[1].var,"y");
    exp[0].term[1].pow[0]=1;
   // exp.term[1].pow[1]=2;

    //exp.term[2].coef=20;
    //strcpy(exp.term[2].var,"yz");
    //exp.term[2].pow[0]=2;
    //exp.term[2].pow[1]=1;
    exp[1].term[0].coef=2;
    strcpy(exp[1].term[0].var,"x");
    exp[1].term[0].pow[0]=1;

    exp[1].term[1].coef=3;
    strcpy(exp[1].term[1].var,"y");
    exp[1].term[1].pow[0]=1;

    for (int i = 0;i < 2; i++)
    {
        if((exp[i].term[i].coef>0) && (i!=0))
        {
            printf("+%d",exp[i].term[i].coef);
        }
        else
        {
            printf("%d",exp[i].term[i].coef);
        }
        for (int j = 0; exp[i].term[i].var[j] != '\0'; j++)
        {
            printf("%c",exp[i].term[i].var[j]);
            if (exp[i].term[i].pow[j] ==1)
            {
            printf("");
            } 
            else
            {
                printf("^%d",exp[i].term[i].pow[j]);
            }
            
        }
    }
   
       int coef=exp[0].term[0].coef;
       char var[10];
       strcpy(var,exp[0].term[0].var);
       int pow[10];
       for (int  i = 0; i < 1; i++)
        {
             pow[i]=exp[0].term[0].pow[i];
        }
    for(int i=1;i<=1;i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("\n%d",coef*exp[i].term[j].coef);
            if(var[0]==exp[i].term[j].var[j])
            printf("%c^%d",exp[j].term[0].var[j],pow[j]+exp[j].term->pow[j]);
            else
            {
               printf("%s",strcat(var[0],exp[j].term->var[j])); 
            }
            
        }
        
    }

}
