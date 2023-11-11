#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Function to return precedence of operators
int precedence(char operator)
{
    switch (operator)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
    default:
        return -1;
    }
}

// Function to check if the scanned character is an operator
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(' || ch == ')');
}

// Main functio to convert infix expression to postfix expression
char *infixToPostfix(char *infix)
{
    int i, j;
    int len = strlen(infix);
    char *postfix = (char *)malloc(sizeof(char) * (len + 2));
    char stack[MAX];
    int top = -1;

    for (i = 0, j = 0; i < len; i++)
    {
        if (infix[i] == ' ' || infix[i] == '\t')
            continue;

        // If the scanned character is operand add it to the postfix expression
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }

        // if the scanned character is '(' push it in the stack
        else if (infix[i] == '(')
        {
            stack[++top] = infix[i];
        }

        // if the scanned character is ')'
        // pop the stack and add it to the
        // output string until empty or '(' found
        else if (infix[i] == ')')
        {
            while (top > -1 && stack[top] != '(')
                postfix[j++] = stack[top--];
            if (top > -1 && stack[top] != '(')
                return "Invalid Expression";
            else
                top--;
        }

        // If the scanned character is an operator
        // push it in the stack
        else if (isOperator(infix[i]))
        {
            while (top > -1 && precedence(stack[top]) >= precedence(infix[i]))
                postfix[j++] = stack[top--];
            stack[++top] = infix[i];
        }
    }

    // Pop all remaining elements from the stack
    while (top > -1)
    {
        if (stack[top] == '(')
        {
            return "Invalid Expression";
        }
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
    return postfix;
}

// Driver code
int main()
{
    char infix[MAX];
    printf("Enter the Infix : ");
    fgets(infix, sizeof(infix), stdin);

    // Function call
    char *postfix = infixToPostfix(infix);
    printf("postfix : %s\n", postfix);
    free(postfix);
    return 0;
}
