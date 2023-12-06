#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct Node *next;
} Node;

struct Stack
{
    Node *top;
};

void initializeStack(struct Stack *stack){
    stack->top = NULL;
}

int isEmpty(struct Stack *stack){
    return(stack->top == NULL);
}

void enque(struct Stack *stack, int data){
    //create a new node
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = data;
    newNode->next = stack->top;

    stack->top = newNode;
}
int deque(struct Stack *stack){
    if(isEmpty(stack)){
        printf("Stack UnderFlow!\n");
        return;
    }
    int data = stack->top->value;

    Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}
int peek(struct Stack *stack){
    if(isEmpty(stack)){
        fprintf(stderr, "Stack is Empty!\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->value;
}
void display(struct Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is Empty!\n");
        return;
    }
    Node *current = stack->top;
    printf("Stack : ");
    while (current != NULL)
    {
        printf("%d -->", current->value);
        current = current->next;
    }
    printf("NULL\n");
    
}

int main()
{
    struct Stack *myStack;
    initializeStack(&myStack);
    int choose, data;
    while (1)
    {
        printf("\n\tSTACK WITH DOUBLE LINKED LIST\n\t______________________________\n");
        printf("\t\t1.Enqueue\n\t\t2.Dequeue\n\t\t3.Display\n\t\t4.Show TOP\n\t\t5.Exit\n");
        printf("\tSelect option : ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            printf("Enter a value : ");
            scanf("%d", &data);
            enque(&myStack, data);
            break;
        case 2:
            deque(&myStack);
            break;
        case 3:
            display(&myStack);
            break;
        case 4:
            int top = peek(&myStack);
            printf("Top = %d", top);
            break;
        case 5:
            exit(1);
        default:
            break;
        }
    }

    return 0;
}
