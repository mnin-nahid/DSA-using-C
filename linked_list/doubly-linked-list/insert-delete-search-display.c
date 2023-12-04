#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *previous, *next;
} *head = NULL;

void insert_first(int value);
void insert_last(int value);
void delete_first();
void delete_last();
void display();
void search(int value);

int main()
{
    int choice, value;
    while (1)
    {
        printf("\tChoice Operation\n\t\t1.Insert First\n\t\t2.Insert Last\n\t\t3.Delete First\n\t\t4.Delete Last\n\t\t5.Display\n\t\t6.Search\n");
        printf("\tSelect Operation : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a value : ");
            scanf("%d", &value);
            insert_first(value);
            break;
        case 2:
            printf("Enter a value : ");
            scanf("%d", &value);
            insert_last(value);
            break;
        case 3:
            delete_first();
            break;
        case 4:
            delete_last();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Enter search value : ");
            scanf("%d", &value);
            search(value);
            break;
        case 7:
            exit(1);
        default:
            break;
        }
    }

    return 0;
}

void insert_first(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->previous = NULL;
    newNode->next = NULL;
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    printf("\t%d insert success!\n", value);
}
void insert_last(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    if(head == NULL){
        newNode->previous = NULL;
        head = newNode;
    }else{
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->previous = temp;        
    }
    printf("\tInsert Value %d success!\n", value);
}
void delete_first()
{
    printf("delete first success\n");
}
void delete_last()
{
    printf("delete last success\n");
}
void display()
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("\tList is Empty!\n");
    }
    else
    {
        printf("\tElement In The List\n\t");
        printf("NULL <--");
        while (temp->next != NULL)
        {
            printf("%d <==> ", temp->value);
            temp = temp->next;
        }
        printf("%d --> NULL\n", temp->value);
    }
}
void search(int value)
{
    printf("search for %d\n", value);
}