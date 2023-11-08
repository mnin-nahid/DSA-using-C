#include <stdio.h>

int main()
{
    int max_size, top = 0;
    printf("Enter the size of the stack : ");
    scanf("%d", &max_size);
    int stack[max_size];
    while (1)
    {
        int chosse;
        int number;
        printf("Chosse an OPeration :\n\t1. insert\n\t2. Delete\n\t3. Display\n");
        scanf("%d", &chosse);

        switch (chosse)
        {
        case 1:
            if (top == max_size)
                printf("Stack is OVERFLOW!\n");
            else
            {
                printf("Enter a number : ");
                scanf("%d", &number);
                stack[top] = number;
                printf("%d is added to the stack[%d]\n", number, top);
                top++;
            }
            break;
        case 2:
            if (top == 0)
                printf("Stack is UNDERFLOW!\n");
            else
            {
                number = stack[--top];
                printf("%d is delete from the stack\n", number);
            }
            break;
        case 3:
            printf("\tSTACK ELEMENT\n--------------------------------\n");
            if (top == 0)
                printf("Stack is EMPTY!\n");
            else
            {
                for (int i = top - 1; i >= 0; i--)
                {
                    printf("%d, ", stack[i]);
                }
                printf("\n");
            }
            break;

        default:
            break;
        }
    }

    return 0;
}