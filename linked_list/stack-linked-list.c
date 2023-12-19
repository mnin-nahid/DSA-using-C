#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

struct Stack {
    struct Node* top;
};

void push(struct Stack* stack, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("\nStack Overflow");
        exit(1);
    }
    temp->data = data;
    temp->link = stack->top;
    stack->top = temp;
}

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

int peek(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->top->data;
    else
        exit(1);
}

void pop(struct Stack* stack) {
    struct Node* temp;
    if (stack->top == NULL) {
        printf("\nStack Underflow");
        // exit(1);
    }
    else {
        temp = stack->top;
        stack->top = stack->top->link;
        free(temp);
    }
}

void display(struct Stack* stack) {
    struct Node* temp;
    if (stack->top == NULL) {
        printf("\nStack Underflow");
        // exit(1);
    }
    else {
        temp = stack->top;
        while (temp != NULL) {
            printf("%d", temp->data);
            temp = temp->link;
            if (temp != NULL)
                printf(" -> ");
        }
    }
}

int main() {
    struct Stack s;
    s.top = NULL;

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
            push(&s, data);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            display(&s);
            break;
        case 4:
            int top = peek(&s);
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