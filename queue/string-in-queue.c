#include <stdio.h>
#include<stdlib.h>

void insert();
void delete();
void show();

int main()
{
    int size, choose;
    printf("Enter Queue Size : ");
    scanf("%d", &size);

    while (1)
    {
        printf("1. Insert\n2. Delete\n3. Show\n4. Exit\n");
        printf("Select a operation : ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            insert();
            break;
        case 2:
            delete(); 
            break;
        case 3:
            show(); 
            break;
        case 4:
            exit(1); 
            break;
        default:
            break;
        }
    }

    return 0;
}

void insert(){
    printf("Insert\n");
}
void delete(){
    printf("Delete\n");
}
void show(){
    printf("show\n");
}
