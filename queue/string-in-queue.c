#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int insert(char queue[30][30], int *front, int *rear, char data[30], int size)
{
    // printf("Insert\n");
    if (*front == -1 && *rear == -1)
    {
        *front = *rear = 0;
        strcpy(queue[*rear], data);
    }
    else if ((*rear + 1) % size == *front)
    {
        return -1;
    }
    else
    {
        *rear = (*rear + 1) % size;
        strcpy(queue[*rear], data);
        return 1;
    }
}
int delete(char queue[30][30], int *front, int *rear, char data[30], int size)
{
    strcpy(data, queue[*front]);
    if (*front == -1)
    {
        return -1;
    }
    else
    {
        if (*front == *rear)
        {
            *front = *rear = -1;
        }
        else
        {

            *front = (*front + 1) % size;
        }
        return 1;
    }
}
void show(char queue[30][30], int *front, int *rear, int size)
{
    int counter = *front;
    if (*front == -1 && *rear == -1)
        printf("Queue is Empty\n");
    else
    {
        printf("Element on Queue \n");
        while (counter != *rear)
        {
            printf("%s\n", queue[counter]);
            // if(counter == *rear) break;
            counter = (counter + 1) % size;
        }
        printf("%s\n", queue[*rear]);
    }
}

int main()
{

    int size, choose, front, rear, funcReplay;
    front = rear = -1;
    char queue[30][30], data[30];

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
            if ((rear + 1) % size == front)
            {
                printf("Queue is Overflow\n");
            }
            else
            {
                printf("Enter a Name : ");
                scanf("%s", data);
                funcReplay = insert(queue, &front, &rear, data, size);
                if (funcReplay == -1)
                    printf("Queue is full\n");
                else
                {
                    printf("\n'%s' is Inserted\n", data);
                    printf("Front = %d \n Rear = %d\n", front, rear);
                }
            }
            break;
        case 2:
            funcReplay = delete (queue, &front, &rear, data, size);
            if (funcReplay == -1)
            {
                printf("Queue is Empty\n");
            }
            else
            {
                printf("'%s' has been deleted success\n", data);
                printf("Front = %d \n Rear = %d\n", front, rear);
            }
            break;
        case 3:
            show(queue, &front, &rear, size);
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