#include "contact.h"

void contact_init(Contact* pc){
    pc->count = 0;
    memset(pc->data, 0, sizeof(pc->data));
}

void Add(Contact* pc){
    assert(pc);
    if(pc->count == 100){
        printf("contact is full!\n");
        return;
    }

    printf("Please input name:\n");
    scanf("%s", pc->data[pc->count].name);

    printf("Please input age:\n");
    scanf("%d", &pc->data[pc->count].age);

    printf("Please input gender:\n");
    scanf("%s", pc->data[pc->count].gender);

    printf("Please input telephone number:\n");
    scanf("%s", pc->data[pc->count].tele);

    printf("Please input address:\n");
    scanf("%s", pc->data[pc->count].addr);

    pc->count++;
    printf("add success!\n");

}

void Show(Contact* pc){
    assert(pc);
    int i = 0;
    printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n","Name","Age","Gender","Tele","Addr");
    for(i = 0; i < pc->count; i++){
        printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",  pc->data[i].name,
                                                pc->data[i].age,
                                                pc->data[i].gender,
                                                pc->data[i].tele,
                                                pc->data[i].addr);
    }
    
}

static int SearchByName(Contact* pc, char* c){
    for(int i = 0; i < pc->count; i++){
        if(strcmp(pc->data[i].name, c) == 0){
            return i;
        }
    }
    return -1;
}

void Dele(Contact* pc){
    assert(pc);
    char name[] = "";
    if(pc->count == 0){
        printf("Contact is empty.\n");
        return;
    }

    printf("Please input the name which you want delete:\n");
    scanf("%s", name);

    int index = SearchByName(pc, name);
    if(index == -1){
        printf("Can't find!\n");
        return;
    }

    for(int i = index; i < pc->count - 1; i++){
        pc->data[i] = pc->data[i+1];
    }
    pc->count--;
    printf("Delete success!\n");
}

void Search(Contact* pc){
    
    assert(pc);
    char name[20];
    printf("Pleace input name which you want search:\n");
    scanf("%s", name);

    int index = SearchByName(pc, name);
    if(index == -1){
        printf("Can't find!\n");
        return;
    }
    printf("%20s\t%5d\t%5s\t%12s\t%20s\n",  pc->data[index].name,
                                            pc->data[index].age,
                                            pc->data[index].gender,
                                            pc->data[index].tele,
                                            pc->data[index].addr);

}

void Modify(Contact* pc){
    assert(pc);
    char name[20];
    printf("Please input name which you want modify his/her information:\n");
    scanf("%s", name);

    int index = SearchByName(pc, name);
    if(index == -1){
        printf("Can't find!\n");
        return;
    }
    printf("Please input name:\n");
    scanf("%s", pc->data[index].name);

    printf("Please input age:\n");
    scanf("%d", &pc->data[index].age);

    printf("Please input gender:\n");
    scanf("%s", pc->data[index].gender);

    printf("Please input telephone number:\n");
    scanf("%s", pc->data[index].tele);

    printf("Please input address:\n");
    scanf("%s", pc->data[index].addr);

    printf("Modify success!\n");
    
}

int cmp_by_name(const void* n1, const void* n2){
    return strcmp(((PeoInfo*)n1)->name, ((PeoInfo*)n2)->name);
}

void Sort(Contact* pc){
    
    assert(pc);
    qsort(pc->data, pc->count, sizeof(pc->data[0]), cmp_by_name);
    printf("Sort success!\n");

}

