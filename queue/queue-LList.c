#include<stdio.h>
#include<stdlib.h>


//Structure for Queue
struct Queue{
    int front;
    int rear;
    int size;
    unsigned capacity;
    int *array;
}

struct Queue *createQueue(unsigned capacity){
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    queue->rear = capacity -1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue *queue){
    return(queue->size == queue->capacity);
}

int isEmpty(struct Queue *queue){
    return (queue->size == 0);
}

void enqueue(struct Queue *queue, int value){
    if(isFull(queue)){
        printf("Queue is Full!\n");
        return;
    }
    queue->rear = (queue->rear +1)% queue->capacity;
    queue->array[queue->rear] = value;
    queue->size = queue->size +1;
    printf("%d is enqueue to queue. Success!\n", value);
}

int dequeue(struct Queue *queue){
    is(isEmpty(queue)){
        return INT_MIN;
    }
    int value = queue->array[queue->front];
    queue->front = (queue->front +1) %queue->capacity;
    queue->size = queue->size -1;
    return value;
}

int front(struct Queue *queue){
    if(isEmpty(queue)){
        return INT_MIN;
    }
    return queue->array[queue->front];
}

int rear(struct Queue *queue){
    if(isEmpty(queue)){
        return INT_MIN;
    }
    return queue->array[queue->rear];
}

int main(){
    int SIZE, operation;
    printf("Enter the Size of the QUEUE : ");
    scanf("%d", &SIZE);
    struct Queue *queue = createQueue(SIZE);
    while(1){
        printf("1. Enqueue\n2. Dequeue\n");
        printf("Chosse : ");
        scanf("%d", &operation);
        switch(operation){
            case 1:
                int value;
                printf("Enter value : ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                dequeue(queue);
                break;
            default:
                printf("Wrong input! try again.\n");
                break;
        }
    }
    return 0;

}