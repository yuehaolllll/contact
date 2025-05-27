#include "contact.h"

/*
//静态版本
void contact_init(Contact* pc){
    pc->count = 0;
    memset(pc->data, 0, sizeof(pc->data));
}
*/

int CheckCapacity(Contact* pc){
    assert(pc);
    if(pc->count == pc->capacity){
        PeoInfo* ptr = (PeoInfo*)realloc(pc->data, sizeof(PeoInfo)*(pc->capacity+ICR_SZ));
        if(ptr == NULL){
            printf("CheckCapacity::%s\n", strerror(errno));
            return 1;
        }else{
            pc->data = ptr;
            pc->capacity += ICR_SZ;
            printf("Increase capacity success!\n");
        }
    }
    return 0;
}


void LoadContact(Contact* pc){

    assert(pc);
    FILE* pfRead = fopen("contact.txt", "r");
    if(pfRead == NULL){
        perror("LoadContact");
        return;
    }

    //以二进制形式读
    PeoInfo temp = {0};
    while(fread(&temp, sizeof(PeoInfo), 1, pfRead) == 1){
        CheckCapacity(pc);

        pc->data[pc->count] = temp;
        pc->count++;
    }

    //关闭文件
    fclose(pfRead);
    pfRead = NULL;

}


//动态版本
int contact_init(Contact* pc){
    assert(pc);
    pc->count = 0;
    PeoInfo* ptr = (PeoInfo*)calloc(DEFAULT_SZ, sizeof(PeoInfo));
    if(ptr == NULL){
        printf("contact_init::%s\n", strerror(errno));
        return 1;
    }else{
        pc->data = ptr;
        pc->capacity = DEFAULT_SZ;
    }

    LoadContact(pc);

    return 0;
}

/*
//静态版本
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
*/



//动态版本
void Add(Contact* pc){
    assert(pc);
    CheckCapacity(pc);

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


void Destroy(Contact* pc){
    assert(pc);
    free(pc->data);
    pc->data = NULL;
}

void SaveContact(const Contact* pc){
    assert(pc);
    FILE* pfWrite = fopen("contact.txt", "w");
    if(pfWrite == NULL){
        perror("SaveContact");
        return;
    }

    //以二进制形式写
    for(int i = 0; i < pc->count; i++){
        fwrite(pc->data+i, sizeof(PeoInfo), 1, pfWrite);
    }

    //关闭文件
    fclose(pfWrite);
    pfWrite = NULL;

}



