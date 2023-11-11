#include <stdio.h>
#include <stdlib.h>

int queue[100], front = -1, rear = -1, size;

void enqueue();
void dequeue();
void display();

int main()
{
    int choice;
    printf("Enter the size of Queue: ");
    scanf("%d", &size);
    do
    {
        printf("\n1. enQueue()\n2. deQueue()\n3. display\n4. exit()\n\nSelect your operation: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Choice right operation\n");
            break;
        }

    } while (1);

    return 0;
}

void enqueue()
{
    int value;

    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        printf("Enter value : ");
        scanf("%d", &value);
        queue[rear] = value;
    }
    else if ((rear + 1) % size == front)
    {
        printf("Queue is Full!\n");
    }
    else
    {
        rear = (rear + 1) % size;
        printf("Enter value : ");
        scanf("%d", &value);
        queue[rear] = value;
        printf("\n Inserted -> %d", value);
    }
}

void dequeue()
{
    int value = queue[front];
    if (front == -1)
        printf("Queue is empty!\n");
    else
    {
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        printf("Delete value is %d\n", value);
    }
}

void display()
{
    int counter = front;
    if (front == -1 && rear == -1)
        printf("Queue is empty!\n");
    else
    {
        printf("\n Front -> %d, Rear -> %d ", front, rear);
        printf("Element of Queue\n");

        while (counter <= rear)
        {
            printf("%d \n", queue[counter]);
            counter = (counter + 1) % size;
        }
    }
}