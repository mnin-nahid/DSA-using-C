#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int insert(char queue[30][30], int *front, int *rear, char data[30], int size)
{
    // printf("Insert\n");
    if (*rear == size - 1)
    {
        return -1;
    }
    else
    {
        if (*front == -1)
            *front = 0;
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
    if (*front == -1 || *front == size)
        printf("Queue is Empty\n");
    else
    {
        printf("Element on Queue \n");
        for (int i = *front; i <= *rear; i++)
        {
            printf("%s\n", queue[i]);
        }
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