#include <stdio.h>
int stack[100], size, top, choice, value;
void push(void);
void pop(void);
void display(void);

int main()
{
    top = -1;
    printf("Enter the size of STACK : ");
    scanf("%d", &size);
    do
    {
        printf("Choice Operation\n 1. push()\n 2. pop()\n 3. display()\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        default:
        {
            printf("\nEnter a valid operation!\n");
        }
        }
    } while (1);
    return 0;
}

void push()
{
    if (top >= size - 1)
    {
        printf("\n\nSTACK is Overflow!\n");
    }
    else
    {
        printf("\nEnter a value to push in STACK : ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("\n\nSuccess to push %d in stack", value);
    }
}

void pop()
{
    if (top >= 0)
    {
        printf("\n\n %d is succesfully popped\n", stack[top]);
        top--;
    }
    else
        printf("\n\n\nSTACK is Underflow!\n");
}

void display()
{
    if (top < 0)
        printf("\n\n\nSTACK is Empty!\n");

    printf("\n\n\nElement in the stack\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
    printf("\nEnter your next choice : ");
}