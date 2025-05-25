#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define MAX_data 100
#define MAX_name 20
#define MAX_gender 10
#define MAX_tele 12
#define MAX_addr 20

typedef struct PeoInfo
{
    char name[MAX_name];
    int age;
    char gender[MAX_gender];
    char tele[MAX_tele];
    char addr[MAX_addr];
}PeoInfo;


typedef struct Contact
{
    PeoInfo data[MAX_data];
    int count;
}Contact;

void contact_init(Contact* pc);
void Add(Contact* pc);
void Show(Contact* pc);
void Dele(Contact* pc);
void Search(Contact* pc);
void Modify(Contact* pc);
void Sort(Contact* pc);

