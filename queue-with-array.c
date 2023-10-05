#include <stdio.h>
#include <stdlib.h>

int size, font, rear, queue[100];
void enqueue();
void dequeue();
void displayQueue();

int font = -1, rear = -1;

int main()
{

    int choice;
    printf("Enter the size of Queue: ");
    scanf("%d", &size);

    do
    {
        printf("\n1. enQueue()\n2. deQueue()\n3. displayQueue\n4. exit()\n\nSelect your operation: ");
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
            displayQueue();
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
    if (rear == size - 1)
        printf("Queue is Overflow\n");
    else
    {
        if (font == -1) font = 0;
        printf("Inset the value: ");
        scanf("%d", &value);
        rear = rear + 1;
        queue[rear] = value;
        printf("enqueue %d success\n", value);
    }
}

void dequeue()
{
    if (font == -1 || font > rear)
    {
        printf("Queue is Underflow\n");
        return;
    }
    else
    {
        printf("%d is delete sucess\n", queue[font]);
        font = font + 1;
    }
}

void displayQueue()
{
    if (font == -1 || font == size)
        printf("Queue is Empty!\n");
    else
    {
        printf("Element of Queue\n");
        for (int i = font; i <= rear; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}