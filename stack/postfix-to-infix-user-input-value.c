#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// dicliaration
int stack[50];
int top = -1;

int tmp = 0;

int priviusChacker = 0;

void push(char ch)
{
    stack[++top] = ch;
}

// char pop(){
//     return stack[top--];
// }

// void convert(char postfix[]){
//     int length, j = 0;
//     char tmp[20];
//     strrev(postfix);
//     length = strlen(postfix);
//     for(int i = 0; i<50; i++){
//         stack[i] = '\0';
//     }
//     printf("The Infix expression is : ");
//     for(int i = 0; i <length; i++){
//         if(postfix[i] == '+' ||postfix[i] == '-' ||postfix[i] == '*' ||postfix[i] == '/'){
//             push(postfix[i]);
//         }else{
//             tmp[j++] = postfix[i];
//             tmp[j++] = pop();
//         }
//     }
//     tmp[j] = postfix[top--];
//     strrev(tmp);
//     puts(tmp);
// }

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    else
        return 0;
}

int whichOperator(char ch)
{
    switch (ch)
    {
    case '+':
        return 1;
        break;
    case '-':
        return 2;
        break;
    case '/':
        return 3;
        break;
    case '*':
        return 4;
        break;
    case '^':
        return 5;
        break;

    default:
        printf("Invalid operator\n");
        break;
    }
}

void calculation(int a, int b, int operator){
    switch (operator)
    {
    case 1:
        //sum
        tmp = a+b;
        break;
    case 2:
        //sub
        tmp = a-b;
        break;
    case 3:
        //div
        tmp = a/b;
        break;
    case 4:
        //mull
        tmp = a*b;
    case 5:
        //pow
        tmp = pow(b, a);
        break;
    default:

        break;
    }
}

int main()
{
    char postfix[50];
    int length, num1, num2;
    char a, b;
    printf("\nEnter the Postfix : ");
    gets(postfix);
    printf("postfix: %s\n", postfix);
    length = strlen(postfix);
    printf("length : %d\n", length);
    for (int i = 0; i < length; i++)
    {
        if (!isOperator(postfix[i]))
        {
            priviusChacker = 1;

            push(postfix[i]);
        }
        else if (isOperator)
        {
            if (priviusChacker == 1)
            {
                printf("Enter the value of : %c", stack[top]);
                scanf("%d", &num1);
                stack[top--];
                printf("Enter the value of : %c", stack[top]);
                scanf("%d", &num2);
                stack[top--];
                calculation(num1, num2, whichOperator(postfix[i]));
            }
            else
            {
                // a = totalValue;
                printf("Enter the value of : %c", stack[top]);
                scanf("%d", &num2);
                b = stack[top--];

                calculation(tmp, num2, whichOperator(postfix[i]));
            }
            //calculation

            priviusChacker = 0;
        }
    }
    printf("Total : %d\n", tmp);
    return 0;
}