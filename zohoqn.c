#include<stdio.h>

//void getInput(int,struct*);
//void output(int,struct*);

struct student
{
    char regno[20];
    char name[40];
};

void output(int rows,struct student *cse){
    printf("============================================\n");
    for (int i = 0; i < rows; i++){
        printf("Student RegisterNo:");
        printf("%s\n",cse[i].regno);
        printf("Enter Student Name:");
        printf("%s\n",cse[i].name);
    }
    printf("============================================\n");
}

void getInput(int numin,struct student *cse){
    for (int i = 0; i < numin; i++){
        printf("Enter Student RegisterNo:\n");
        scanf("%s",cse[i].regno);
        printf("Enter Student Name:\n");
        scanf("%s",cse[i].name);
    }
}

void main(){
    struct student cse[2];
    getInput(2,cse);
    output(2,cse);
}