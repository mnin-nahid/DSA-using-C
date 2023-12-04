#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
} *head = NULL;

void insert_first(int value);
void insert_last(int value);
void delete_first();
void delete_last();
void display();

int main()
{
    int operation;
    int value;
    while (1)
    {
        printf("\t\tChose your operation\n\t\t\t1. insert first\n\t\t\t2. insert last\n\t\t\t3. delete first\n\t\t\t4. delete last\n\t\t\t5. Display\n\t\t\t6. exit\n");
        printf("\t\t select option : ");
        scanf("%d", &operation);
        switch (operation)
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
            exit(1);

        default:
            printf("\t\tChose valide Option!!\n");
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
    printf("\t\tinsert %d to linked list. Success!\n", value);
}
void insert_last(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("\t\tinsert %d to linked list. Success!\n", value);
}
void delete_first()
{
    struct Node *temp = head;
    temp = temp->next;
    printf("\t\t%d is delete success!\n", head->value);
    head = temp;
}
void delete_last()
{
    struct Node *prev;
    struct Node *temp = head;
    if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
    }
    printf("\n\t\t%d is delete succcess!\n", temp->value);
}
void display()
{
    if (head == NULL)
        printf("\t\tLinked list Empty!\n");
    else
    {
        struct Node *temp;
        // temp = (struct Node*)malloc(sizeof(struct Node));
        temp = head;

        printf("\n\n\t\tList value are\n\t");
        while (temp->next != NULL)
        {
            printf("%d --> ", temp->value);
            temp = temp->next;
        }
        printf("%d --> NULL\n", temp->value);
    }
}