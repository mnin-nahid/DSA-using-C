// C program to evaluate value of a postfix expression
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack type
typedef struct Stack
{
    int top;
    unsigned capacity;
    int *array;
}STACK;

// Stack Operations
STACK *createStack(unsigned capacity)
{
    STACK *stack = (STACK *)malloc(sizeof(STACK));

    if (!stack)
        return NULL;

    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));

    if (!stack->array)
        return NULL;

    return stack;
}

int isEmpty(STACK *stack)
{
    return stack->top == -1;
}

char peek(STACK *stack)
{
    return stack->array[stack->top];
}

char pop(STACK *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(STACK *stack, char op)
{
    stack->array[++stack->top] = op;
}

// The main function that returns value of a given postfix expression
int evaluatePostfix(char *exp)
{
    // Create a stack of capacity equal to expression size
    STACK *stack = createStack(strlen(exp));
    // See if stack was created successfully
    if (!stack)
        return -1;

    // Scan all characters one by one
    for (int i = 0; exp[i]; ++i)
    {

        // If the scanned character is an operand(number here), push it to the stack.
        if (isdigit(exp[i]))
            push(stack, exp[i] - '0');

        // If the scanned character is an operator,pop two elements from stack apply the operator
        else
        {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i])
            {
            case '+':
                push(stack, val2 + val1);
                break;
            case '-':
                push(stack, val2 - val1);
                break;
            case '*':
                push(stack, val2 * val1);
                break;
            case '/':
                push(stack, val2 / val1);
                break;
            }
        }
    }
    return pop(stack);
}

int main()
{
    char postfix[50];
    printf("Enter the postfix exp : ");
    gets(postfix);

    // Function call
    printf("Postfix evaluation: %d\n", evaluatePostfix(postfix));
    return 0;
}
