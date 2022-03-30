#include<stdio.h>
#include<string.h>

struct FamilyMember{
    
};

void findMoraponnu(struct FamilyMember *fam,char* inputname){
    char inname[40];
    strcpy(inname,inputname);
    char mothername[40],gma[40],mama[40];
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(inname,fam[i].name)==0)
        {
            strcpy(mothername,fam[i].mothername);
            for (int j = 0; j < 5; j++)
            {
                if (strcmp(mothername,fam[j].mothername)==0)
                {
                    strcpy(gma,fam[j].mothername);
                }
            }
        }
    }
    for (int j = 0; j < 5; j++)
    {
        if ((stramp(gma,fam[j].mothername)==0) && (strcmp(fam[j].gender,"M")))
        {
            strcpy(mama,fam[j].name);
        }
        
    }
    printf("%s\n",mama);
    printf("%s\n",mothername);
}

void main(){
    struct FamilyMember family[10];

    strcpy(family[0].name,"jeevaraaj\0");
    strcpy(family[0].gender,"M\0");
    strcpy(family[0].mothername,"jeyanthi\0");
    strcpy(family[0].fathername,"manimaran\0");

    strcpy(family[1].name,"jeyanthi\0");
    strcpy(family[1].gender,"F\0");
    strcpy(family[1].mothername,"pandiammal\0");
    strcpy(family[1].fathername,"manoharan\0");
    
    strcpy(family[2].name,"Aanand\0");
    strcpy(family[2].gender,"M\0");
    strcpy(family[2].mothername,"pandiammal\0");
    strcpy(family[2].fathername,"manoharan\0");
    
    strcpy(family[3].name,"bharathi\0");
    strcpy(family[3].gender,"F\0");
    strcpy(family[3].mothername,"pandiammal\0");
    strcpy(family[3].fathername,"manoharan\0");
    
    strcpy(family[4].name,"keerthy\0");
    strcpy(family[4].gender,"F\0");
    strcpy(family[4].mothername,"Aanand\0");
    strcpy(family[4].fathername,"malathi\0");

    char name[40];
    printf("Enter a name to find moraponnu\n");
    scanf("%s",name);
    findMoraponnu(family,name);
}