#include "contact.c"

void menu(){
    printf("\n");
    printf("****** 1.Add        2.Dele   ******\n");
    printf("****** 3.Search     4.Modify ******\n");
    printf("****** 5.Show       6.Sort   ******\n");
    printf("******       0.Exit          ******\n");
}

int main(){

    int input;
    Contact con;
    contact_init(&con);
    do{
        menu();
        scanf("%d", &input);
        switch(input){
            case 1:
                Add(&con);
                break;
            case 2:
                Dele(&con);
                break;
            case 3:
                Search(&con);
                break;
            case 4:
                Modify(&con);
                break;
            case 5:
                Show(&con);
                break;
            case 6:
                Sort(&con);
                break;
            case 0:
                Destroy(&con);
                printf("EXIT\n");
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    }while(input);
    
}