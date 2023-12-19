#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *previous;
    struct node *next;
} Node;

Node *head = NULL;

void insert_first(int value);
void insert_last(int value);
void insert_condition(int value);

void delete_first();
void delete_last();
void delete_condition();

void display();

int main()
{
    int choice, value;
    while (1)
    {
        printf("\n\t*********Menu*********\n");
        printf("\t1. insert first\n\t2. insert last\n\t3. insert condition\n\t4. delete first\n\t5. insert last\n\t6. delete condition\n\t7. Display\n\tSelect>");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value :");
            scanf("%d", &value);
            insert_first(value);
            break;
        case 2:
            printf("Enter value : ");
            scanf("%d", &value);
            insert_last(value);
            break;
        case 3:
            int condition, conValue;
            printf("Enter Value : ");
            scanf("%d", &value);
            insert_condition(value);
            break;
        case 4:
            delete_first();
            break;
        case 5:
            delete_last();
            break;
        case 6:
            delete_condition();
            break;
        case 7:
            display();
            break;
        default:
            break;
        }
    }

    return 0;
}

void insert_first(int value)
{
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->previous = NULL;
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
        // display();
    }
    else
    {
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
        // display();
    }
}
void insert_last(int value)
{
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));

    newNode->data = value;
    newNode->next = NULL;
    newNode->previous = NULL;
    if (head == NULL)
    {
        head = newNode;
        // newNode->previous = NULL;
        // display();
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->previous = temp;
        // display();
    }
}
void insert_condition(int value)
{
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    if (head == NULL)
    {
        newNode->previous = NULL;
        newNode->next = NULL;
        head = newNode;
        printf("List was empty! insert success!\n");
        // display();
    }
    else
    {

        int condition, conValue;
        printf("1. after\n2. before\nselect>");
        scanf("%d", &condition);
        printf("Enter conditions value: ");
        scanf("%d", &conValue);
        Node *temp = head;
        temp = head;
        Node *prev = head;
        prev = temp;
        switch (condition)
        {
        case 1:
            while (prev->data != conValue)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = newNode;
            newNode->previous = prev;
            newNode->next = temp;
            temp->previous = newNode;
            break;
        case 2:
            while (temp->data != conValue)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = newNode;
            newNode->previous = prev;
            newNode->next = temp;
            temp->previous = newNode;
            break;
        default:
            break;
        }
    }
}

void delete_first()
{
    if (head == NULL)
    {
        printf("<= List is Empty=>\n");
        return;
    }
    else
    {
        if (head->next == NULL)
            head = NULL;
        else
        {

            head = head->next;
            head->previous = NULL;
        }
    }
}
void delete_last()
{
    if (head == NULL)
    {
        printf("<=List is Empty!=>\n");
        return;
    }
    else
    {
        if (head->next == NULL)
        {
            head = NULL;
        }
        else
        {

            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->previous->next = NULL;
            free(temp);
        }
    }
}
void delete_condition()
{
    if (head == NULL)
    {
        printf("<=List is Empty!=>\n");
        return;
    }
    else
    {
        if (head->next == NULL)
        {
            head = NULL;
        }
        else
        {

            int valueCon;
            printf("Which value you want to delete? : ");
            scanf("%d", &valueCon);
            Node *temp = head;
            while (temp->data != valueCon)
            {
                temp = temp->next;
            }
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
            printf("delete success!\n");
            // display();
        }
    }
}

void display()
{
    Node *temp = head;

    if (head == NULL)
    {
        printf("<=List Empty=>\n");
        return;
    }
    else
    {
        printf("NULL <==>");
        while (temp->next != NULL)
        {
            printf(" %d <===> ", temp->data);
            temp = temp->next;
        }
        printf(" %d => NULL\n", temp->data);
    }
}