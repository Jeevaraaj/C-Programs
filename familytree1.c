#include<stdio.h>
#include<string.h>



struct FamilyMember
{
    char name[20];
    char gender[2];
    char motherName[20];
    char faterName[20];
};

void main()
{
  struct FamilyMember member[] = {
    {"Manibalan","M","saraswathi","jayakannan"},
    {"saraswathi","F","kuruvammal","thirupathi"},
    {"jayakannan","M","dhanam","alagarsamy"},
    {"sakaravarthy","M","saraswathi","jayakannan"},
    {"kayalvizhi","F","keerthi","sambath"},
    {"keerthi","F","dhanam","alagarsamy"},
    {"sambath","M","kuruvammal","thirupathi"},
  };
}
