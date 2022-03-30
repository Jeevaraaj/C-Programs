#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct expression{
    int no_of_terms;
    struct term{
        char var[10];
        int coef;
        int no_of_var;
        int pow[10];
    }term[10];
};

void do_multiply(struct term exp1_term,struct term exp2_term,struct term* res_term);
void do_simplify(struct term* term1,struct term* term2,int term_no,struct expression* result);
void separate_terms(char input[],struct expression* exp);
void store_term(char term[],struct expression* exp,int term_no);
int stringToInt(int start_pos,char temp[],int *num);
void print_result(struct expression result);

void main(){
    struct expression exp1,exp2,result;

    char input1[]="3x+4y";
    char input2[]="-3x^2-10xy-8y^2";

    separate_terms(input1,&exp1);
    separate_terms(input2,&exp2);

    int k=0;
    for(int i=0;i<exp1.no_of_terms;i++){
        for(int j=0;j<exp2.no_of_terms;j++){
            do_multiply(exp1.term[i],exp2.term[j],&result.term[k]);
            k++;
        }
    }
    result.no_of_terms=k;


    for(int i=0;i<result.no_of_terms;i++){
        for(int j=i+1;j<result.no_of_terms;j++){
            if(strlen(result.term[i].var) == strlen(result.term[j].var)){
                do_simplify(&result.term[i],&result.term[j],j,&result);
            }
        }
    }

    print_result(result);

}

void do_simplify(struct term* term1,struct term* term2,int term_no,struct expression* result){
    int i,j,flag;
    if(strcmp(term1->var,term2->var)==0){
        flag=0;
        for(i=0;i<term1->no_of_var;i++){
            if(term1->pow[i]==term2->pow[i]){
                flag=1;
            }
        }
        if(flag==1){
            term1->coef=term1->coef+term2->coef;
            for(j=term_no;j<result->no_of_terms;j++){
                result->term[j]=result->term[j+1];
            }
            result->no_of_terms--;
        }
    }
}

void separate_terms(char input[],struct expression* exp){
    int i,j,k,slice_pos=0,term_no=0;

    for(i=0;input[i]!='\0';i++){
        if(input[i]=='+' || (input[i]=='-' && i!=0 && input[i-1]!='^')){
            char term[10];
            for(j=slice_pos,k=0;j<i;j++){
                term[k++]=input[j];
            }
            term[k]='\0';
            store_term(term,exp,term_no);
            term_no++;
            slice_pos=i;
        }
    }
    if(input[i]=='\0'){
        char term[10];
        for(j=slice_pos,k=0;j<i;j++){
            term[k++]=input[j];
        }
        term[k]='\0';
        store_term(term,exp,term_no);
        term_no++;
    }
    exp->no_of_terms=term_no;
}

void store_term(char term[],struct expression* exp,int term_no){
    int i,j,pow,coef,k=0,no_of_var=0;

    for(i=0;term[i]!='\0';i++){
        if(isalpha(term[i])){
            exp->term[term_no].var[no_of_var++]=term[i];
        }
    }
    exp->term[term_no].var[no_of_var]='\0';
    exp->term[term_no].no_of_var=no_of_var;


    exp->term[term_no].coef=1;
    for(i=0;i<no_of_var;i++){
        exp->term[term_no].pow[i]=1;
    }


    //printf("%s\n",term);
    for(i=0;term[i]!='\0';){

        if((term[i]=='-' || term[i]=='+') && isalpha(term[i+1])){
            if(term[i]=='-'){
                exp->term[term_no].coef=-1;
            }
            i=i+2;
            //continue;
        }

        else if(isdigit(term[i])){
            coef=0;
            j=stringToInt(i,term,&coef);
            if(term[i-1]=='-'){
                coef=coef*-1;
            }
            i=j;
            exp->term[term_no].coef=coef;
            //continue;
        }

        else if(term[i]=='^' && term[i+1]=='-'){
            pow=0;
            j=stringToInt(i+2,term,&pow);
            //printf("%d\n",pow);
            if(term[i+1]=='-'){
                pow=pow*-1;
            }
            i=j;
            exp->term[term_no].pow[k++]=pow;
            //continue;
        }
        else if(term[i]=='^'){
            pow=0;
            j=stringToInt(i+1,term,&pow);
            //printf("%d ",pow);
            i=j;
            exp->term[term_no].pow[k++]=pow;
            //continue;
        }
        else{
            i++;
        }
    }

}

int stringToInt(int start_pos,char temp[],int *num){
    int j;
    for(j=start_pos;isdigit(temp[j]);j++){
        *num=*num * 10 + temp[j] - '0';
    }
    return j;
}

void print_result(struct expression result){
    for (int i = 0;i < result.no_of_terms; i++){
        if(result.term[i].coef>0 && i!=0){
            if(result.term[i].coef == 1){
                printf("+",result.term[i].coef);
            }
            else{
                printf("+%d",result.term[i].coef);
            }
        }
        else{
            if(result.term[i].coef == -1){
                printf("-",result.term[i].coef);
            }
            else{
                printf("%d",result.term[i].coef);
            }
        }

        for (int j = 0; j<result.term[i].no_of_var; j++){
            printf("%c",result.term[i].var[j]);
            if (result.term[i].pow[j] ==1){
                printf("");
            }
            else{
                printf("^%d",result.term[i].pow[j]);
            }

        }
    }
}

void do_multiply(struct term exp1_term,struct term exp2_term,struct term* res_term){
    res_term->coef=exp1_term.coef * exp2_term.coef;
    int a,b,c=0,flag;
    for(a=0;a<exp1_term.no_of_var;a++){
        flag=0;
        for(b=0;b<exp2_term.no_of_var;b++){
            if(exp1_term.var[a] == exp2_term.var[b]){
                flag=1;
                res_term->var[c]=exp1_term.var[a];
                res_term->pow[c++]=exp1_term.pow[a] + exp2_term.pow[b];
                break;
            }
        }
        if(flag==0){
            res_term->var[c]=exp1_term.var[a];
            res_term->pow[c++]=exp1_term.pow[a];
        }
    }
    for(b=0;b<exp2_term.no_of_var;b++){
        flag=0;
        for(a=0;a<exp1_term.no_of_var;a++){
            if(exp2_term.var[b] == exp1_term.var[a]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            res_term->var[c]=exp2_term.var[b];
            res_term->pow[c++]=exp2_term.pow[b];
        }
    }
    res_term->no_of_var=c;


   for(int i=0;i<res_term->no_of_var && res_term->no_of_var >1;i++){
        char temp;int pow_temp;
        for(int j=i+1;j<res_term->no_of_var;j++){
            if(res_term->var[i] > res_term->var[j]){
                temp=res_term->var[i];
                res_term->var[i]=res_term->var[j];
                res_term->var[j]=temp;

                pow_temp=res_term->pow[i];
                res_term->pow[i]=res_term->pow[j];
                res_term->pow[j]=pow_temp;
            }
        }
    }
}