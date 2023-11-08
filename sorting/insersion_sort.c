#include <stdio.h>
int insersion_sort(int array[], int length)
{
    for (int i = 1; i < length; i++)
    {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}
int main()
{
    int array[] = {4, 9, 1, 3, 8, 2, 6, 7, 5};
    int length = sizeof(array) / sizeof(array[1]);

    insersion_sort(array, length);

    // for print the array
    for (int i = 0; i < length; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");
}

// #include <stdio.h>

// void insersion_sort(int arr[], int length);

// int main()
// {
//     int array[] = {4, 9, 1, 3, 8, 2, 6, 7, 5};
//     int length = sizeof(array) / sizeof(array[1]);
//     insersion_sort(array, length);
//     for (int i = 0; i < length; i++)
//     {
//         printf("%d, ", array[i]);
//     }
//     printf("\n");
//     return 0;
// }

// void insersion_sort(int arr[], int length){
//     for(int i = 1; i < length; i++){
//         int key = arr[i];
//         int j = i-1;
//         while (j >= 0 && arr[j] > key)
//         {
//             arr[j+1] = arr[j];
//             j = j -1;
//         }
//         arr[j+1] = key;

//     }
// }