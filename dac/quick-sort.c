#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *x, int *y);
void quicksort(int array[], int length);
void quicksort_recursion(int array[], int low, int high);
int partition(int array[], int low, int high);
int main()
{
    int array[] = {4, 9, 2, 1, 8, 5, 96, 34, 91};
    int length = sizeof(array) / sizeof(array[1]);

    quicksort(array, length);

    for (int i = 0; i < length; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");
    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(int array[], int length)
{
    //seed for random number
    srand(time(NULL));
    quicksort_recursion(array, 0, length - 1);
}

void quicksort_recursion(int array[], int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(array, low, high);
        quicksort_recursion(array, low, pivot_index - 1);
        quicksort_recursion(array, pivot_index + 1, high);
    }
}

int partition(int array[], int low, int high){

    //rendom pivot
    int pivot_index = low + (rand()%(high - low));
    if(pivot_index != high){
        swap(&array[pivot_index], &array[high]);
    }
    int pivot_value = array[high];
    int i = low;
    for(int j = low; j< high; j++){
        if(array[j] <= pivot_value){
            swap(&array[i], &array[j]);
            i++;
        }
    }
    swap(&array[i], &array[high]);

    return i;
}