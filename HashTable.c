/******************************************************************************
Hashtable Implementation
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    char name[255];
    int age;
}person;

person * hash_table[MAX];

unsigned int hash(char *name){
    int length = strlen(name);
    unsigned int hash_value=0;
    for(int i=0; i<length;i++){
        hash_value+=name[i];
        hash_value=(hash_value*name[i])%MAX;
    }
    return hash_value;
}

void init_hash_table(){
    for(int i=0; i<MAX; i++){
        hash_table[i] = NULL;
    }
}

void print_table(){
    for(int i=0; i<MAX; i++){
        if(hash_table[i]==NULL)
        printf("\t%i\t---\t--\n",i);
        else{
            printf("\t%i\t%s\t%d\n",i,hash_table[i]->name,hash_table[i]->age);
        }
    }
}

bool insert(person *p){
    if(p==NULL) return false;
    int index = hash(p->name);
    for(int i=0; i<MAX; i++){
        int try = (index+1)%MAX;
        if(hash_table[try]==NULL){
            hash_table[try]=p;
            return true;
        }
    }
    return false;
}

person * find(char *name){
    int index = hash(name);
    for(int i=0; i<MAX; i++){
        int try = (index+1)%MAX;
        if(hash_table[try]!=NULL && strncmp(hash_table[try]->name, name,MAX)==0){
            return hash_table[try];
        }
    }
    return NULL;
}

int main()
{
    init_hash_table();
    
    person mukul ={.name="Mukul",.age=20};
    insert(&mukul);
    print_table();
    printf("Name: %s\tAge: %d",find("Mukul")->name,find("Mukul")->age);

    return 0;
}

