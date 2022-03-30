#include<stdio.h>
#include<string.h>
#include<malloc.h>


struct member{
    char name[30];
    char father_name[30];
    char mother_name[30];
    char gender[7];
};

struct family{
    char gender[7];
    char name[30];
    int no_of_sons;
    int no_of_daugthers;
    int no_of_brothers;
    int no_of_sisters;
    struct family *father;
    struct family *mother;
    struct family *brothers[5];
    struct family *sisters[5];
    struct family *sons[5];
    struct family *daugthers[5];
};

void connect_Parents(struct family* family[], int n, int index, char father[], char mother[]){

    int i;
    for(i=0;i<n;i++){
        if(strcmp(father,family[i]->name)==0){
            family[index]->father=family[i];
        }
        else if(strcmp(mother,family[i]->name)==0){
            family[index]->mother=family[i];
        }
    }

}

void connect_Siblings(struct family* family[], int n, int index, char father[], char mother[]){

    int i,x=0,y=0;
    for(i=0;i<n;i++){
        if(i !=index && family[i]->father!=NULL && strcmp(father,family[i]->father->name)==0 && strcmp(mother,family[i]->mother->name)==0 ){
            if(strcmp(family[i]->gender,"male")==0){
                family[index]->brothers[x++]=family[i];
             }
             else{
                family[index]->sisters[y++]=family[i];
             }
        }
    }
    family[index]->no_of_brothers=x;
    family[index]->no_of_sisters=y;

}

void connect_Children(struct family* family[], int n, int index){
    int i,x=0,y=0;
    for(i=0;i<n;i++){
        if(family[i]->father!=NULL && (strcmp(family[i]->father->name,family[index]->name)==0 || strcmp(family[i]->mother->name,family[index]->name)==0)){
            if(strcmp(family[i]->gender,"male")==0){
                family[index]->sons[x++]=family[i];
             }
             else{
                family[index]->daugthers[y++]=family[i];
             }
        }
    }
    family[index]->no_of_sons=x;
    family[index]->no_of_daugthers=y;
}

void createFamilyStructure(struct member mem[],int n,struct family* family_mem[]){
    int i;
    for(i=0;i<n;i++){
        family_mem[i]=(struct family*)malloc(sizeof(struct family));
        strcpy(family_mem[i]->name,mem[i].name);
        strcpy(family_mem[i]->gender,mem[i].gender);
    }

    for(i=0;i<n;i++){
        if(strlen(mem[i].father_name)>0)
            connect_Parents(family_mem, n, i, mem[i].father_name, mem[i].mother_name);
    }

    for(i=0;i<n;i++){
        if(strlen(mem[i].father_name)>0){
            connect_Siblings(family_mem, n, i, mem[i].father_name, mem[i].mother_name);
            connect_Children(family_mem, n, i);
        }
    }

}


void main(){
    int n;
    struct member mem[]=
    {
        {"krish","mani","lakshmi","male"},
        {"aathi","mani","lakshmi","male"},
        {"lakshmi","chary","maha","female"},
        {"mani","raman","jeya","male"},
        {"sundari","raman","jeya","female"},
        {"ramanan","chary","maha","male"},
        {"uma","chary","maha","female"},
        {"revathi","shiva","uma","female"},
        {"roja","jegan","sundari","female"},
        {"karthik","jegan","sundari","male"},
        {"harini","ramanan","sharmila","female"},
        {"srini","ramanan","sharmila","male"},
        {"sharmila","","","female"},
        {"chary","","","male"},
        {"maha","","","female"},
        {"raman","","","male"},
        {"jeya","","","female"},
        {"shiva","","","male"},
        {"jegan","","","male"}
    };
    n=sizeof(mem)/sizeof(mem[0]);

    struct family *family[n];
    createFamilyStructure(mem,n,family);

    int i,flag=0;
    char name[30];
    printf("Enter a name: ");
    scanf("%s",name);

    for(i=0;i<n;i++){
        if(strcmp(family[i]->name,name)==0){
            flag=1;
            break;
        }
        else{
            flag=0;
        }
    }

    if(flag==0){
        printf("unknown name");
        return -1;
    }


        for(int j=0;j<family[i]->mother->no_of_brothers;j++){
            for(int k=0;k<family[i]->mother->brothers[j]->no_of_daugthers;k++){
                 printf("%s -> %s\n",family[i]->name,family[i]->mother->brothers[j]->daugthers[k]->name);
            }
        }
        for(int j=0;j<family[i]->father->no_of_sisters;j++){
            for(int k=0;k<family[i]->father->sisters[j]->no_of_daugthers;k++){
                 printf("%s -> %s\n",family[i]->name,family[i]->father->sisters[j]->daugthers[k]->name);
            }
        }
}