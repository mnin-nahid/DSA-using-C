#include <stdio.h>

void bubble_sort(int arr[], int length);
int main()
{
    int array[] = {14, 1,13, 7, 5,15, 4, 6,12, 11, 3, 8, 2, 9, 0, 10, 16, 17};
    int arr_size = sizeof(array) / sizeof(array[1]);
    // int i = 0;
    bubble_sort(array, arr_size);

    for (int i = 0; i < arr_size; i++)
    {
        printf(" %d : %d \n ", i, array[i]);
    }

    return 0;
}

void bubble_sort(int arr[], int length)
{
    int att = 0;
    int swapped = 0;
    do
    {
        swapped = 0;
        for (int i = 0; i < (length - 1 - att); i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
        att++;
    } while (swapped);

    printf("Attempt : %d\n", att);
}