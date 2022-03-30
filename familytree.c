/*#include<stdio.h>

struct family
{
};

struct child
{

};

struct amma
{

};

struct appa
{

};

void main(){

}

void findMoraponnu(){

}*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Member{
	char name[30];
	int gender;
	struct Member *father, *mother;
	int son_count, daug_count, bro_count, sis_count;
	struct Member *son[5], *daughter[5], *brother[5], *sister[5];
};
typedef struct Member member;

typedef struct Tuple{
	char name[30];
	member *address;
}tuple;

typedef struct HashMap{
	tuple *data[100];
	int size;
}hashmap;

typedef struct Records{
	char name[30],father[30],mother[30];
	int gender;
}record;

hashmap hm;
int findMember(char name[30]){
	int i;
	for(i=0;i<hm.size;i++){
		if(strcmp(hm.data[i]->name,name)==0){
			return i;
		}
	}
	return -1;
}

void constructor(member *mem,char name[30],int gender){
	
	strcpy(mem->name,name);
	mem->gender = gender;
	mem->bro_count = 0;
	mem->sis_count = 0;
	mem->son_count = 0;
	mem->daug_count = 0;
	mem->father = NULL;
	mem->mother = NULL;
}

int getParent(char name[30],int gender){
	int index = findMember(name);
	if(index == -1){
		index = hm.size;
		hm.data[index] = (tuple *)malloc(sizeof(tuple));
		strcpy(hm.data[index]->name,name);
		hm.data[index]->address = (member *)malloc(sizeof(member));
		constructor(hm.data[index]->address,name,gender);
		hm.size++;
	}
	return index;
}

void connectBro(int child_index,int f_index){
	int index,i;
	
	member *father = hm.data[f_index]->address;
	member *child = hm.data[child_index]->address;
	member *bro;
	
	if(father->son_count>0){
		index = child->bro_count = father->son_count;
		for(i=0;i<index;i++){
			bro = father->son[i];
			child->brother[i] = bro;
			if(child->gender == 1){
				bro->brother[bro->bro_count] = child;
				bro->bro_count++;
			}
			else{
				bro->sister[bro->sis_count] = child;
				bro->sis_count++;
			}

		}
	}
}

void connectSis(int child_index,int f_index){
	int index,i;
	
	member *father = hm.data[f_index]->address;
	member *child = hm.data[child_index]->address;
	member *sis;
	
	if(father->daug_count>0){
		index = child->sis_count = father->daug_count;
		for(i=0;i<index;i++){
			sis = father->daughter[i];
			child->sister[i] = sis;
			if(child->gender == 1){
				sis->brother[sis->bro_count] = child;
				sis->bro_count++;
			}
			else{
				sis->sister[sis->sis_count] = child;
				sis->sis_count++;
			}

		}
	}
}

void connectChild(int child_index, int f_index, int m_index){
	int index;
	member *father = hm.data[f_index]->address;
	member *mother = hm.data[m_index]->address;
	member *child = hm.data[child_index]->address;
	
	if(child->gender){
		index = father->son_count++;
		mother->son_count++;
		father->son[index] = child;
		mother->son[index] = child;
	}
	else{
		index = father->daug_count++;
		mother->daug_count++;
		father->daughter[index] = child;
		mother->daughter[index] = child;
	}
}

void createFamily(record a,int child_index){
	int f_index,m_index;
	member *mem = hm.data[child_index]->address;
	
	f_index = getParent(a.father,1);
	m_index = getParent(a.mother,0);
	
	mem ->father = hm.data[f_index]->address;
	mem ->mother = hm.data[m_index]->address;
	
	connectBro(child_index,f_index);
	connectSis(child_index,f_index);
	connectChild(child_index,f_index,m_index);
	
}

void createMember(record a){
	int child_index;

	hm.data[hm.size] = (tuple *)malloc(sizeof(tuple));
	strcpy(hm.data[hm.size]->name,a.name);
	hm.data[hm.size]->address = (member *)malloc(sizeof(member));
	
	constructor(hm.data[hm.size]->address,a.name,a.gender);
	child_index = hm.size;
	hm.size++;
	createFamily(a,child_index);
	
}

void getDetails(member *mem){
	
	printf("\n%s %d %d %d %d %d",mem->name,
	mem->gender,
	mem->bro_count,
	mem->sis_count,
	mem->son_count,
	mem->daug_count);
}

void printTable(){
	int i;
	printf("\nSize: %d ",hm.size);
	for(i=0;i<hm.size;i++){
		getDetails(hm.data[i]->address);
		//printf("\n%d %s",i,hm.data[i]->name);
	}
}

void getNamesFemale(member *mem,int gender){
	int i,j;
	
	if(gender){
		for(i=0;i<mem->sis_count;i++){
			for(j=0;j<mem->sister[i]->daug_count;j++){
				printf("\n%s",mem->sister[i]->daughter[j]->name);
			}
		}
		
	}
	else{
		for(i=0;i<mem->bro_count;i++){
			for(j=0;j<mem->brother[i]->daug_count;j++){
				printf("\n%s",mem->brother[i]->daughter[j]->name);
			}
		}
	}
}

void getNamesMale(member *mem,int gender){
	int i,j;
	
	if(gender){
		for(i=0;i<mem->sis_count;i++){
			for(j=0;j<mem->sister[i]->son_count;j++){
				printf("\n%s",mem->sister[i]->son[j]->name);
			}
		}
		
	}
	else{
		for(i=0;i<mem->bro_count;i++){
			for(j=0;j<mem->brother[i]->son_count;j++){
				printf("\n%s",mem->brother[i]->son[j]->name);
			}
		}
	}
}

void findPartner(char name[30]){
	int index = findMember(name);
	if(index > -1){
		member *mem = hm.data[index]->address;
		if(mem->gender){
			getNamesFemale(mem->father,1);
			getNamesFemale(mem->mother,0);
		}
		else{
			getNamesMale(mem->father,1);
			getNamesMale(mem->mother,0);	
		}
	}
	else{
		printf("\nUnknown to Family");
	}	
}

int isDuplicate(int index){
	if(hm.data[index]->address->father == NULL){
		printf("\nDon't Enter Duplicate");
		return 0;
	}
	return 1;
}

void main(){
	
	record table[] = {
		{"hari","govind","viji",1},{"govind","bala","raji",1},{"ramani","govind","viji",0},
		{"kanna","venu","jillu",1},{"viji","venu","jillu",0},{"aravind","govind","viji",1},
		{"jeya","bala","raji",0},{"sushma","kanna","renuka",0},{"poorani","seshu","jeya",0},
		{"gokul","jeya","seshu",1}
	};

	int n = 10,i,hashMapIndex ;
	hm.size = 0;
	
	for(i=0;i<n;i++){
		hashMapIndex = findMember(table[i].name);
		if(hashMapIndex == -1){
			createMember(table[i]);
		}
		else{
			createFamily(table[i],hashMapIndex);
		}
	}
	findPartner("hari");
}