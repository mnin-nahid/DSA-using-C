#include <stdio.h>

void merge_sort(int array[], int length);
void merge_sort_recursion(int array[], int left, int right);
void merge_sorted_arrays(int array[], int left, int mid, int right);
int main()
{
    int array[] = {9, 4,30, 50, 2, 8, 1, 7, 0, 3, 2, 5, 6};
    int length = sizeof(array) / sizeof(array[1]);

    merge_sort(array, length);

    // print array
    for (int i = 0; i < length; i++)
        printf("%d, ", array[i]);
    printf("\n");

    return 0;
}

void merge_sort(int array[], int length)
{
    merge_sort_recursion(array, 0, length - 1);
}

void merge_sort_recursion(int array[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort_recursion(array, left, mid);
        merge_sort_recursion(array, mid + 1, right);

        merge_sorted_arrays(array, left, mid, right);
    }
}

void merge_sorted_arrays(int array[], int left, int mid, int right)
{
    int left_length = mid - left + 1;
    int right_length = right - mid;

    int temp_left[left_length];
    int temp_right[right_length];

    int i, j, k;

    for (int i = 0; i < left_length; i++)
    {
        temp_left[i] = array[left + i];
    }
    for (int i = 0; i < right_length; i++)
    {
        temp_right[i] = array[mid + 1 + i];
    }

    for (int i = 0, j = 0, k = left; k <= right; k++)
    {
        if ((i < left_length) && (j >= right_length || temp_left[i] <= temp_right[j]))
        {
            array[k] = temp_left[i];
            i++;
        }
        else
        {
            array[k] = temp_right[j];
            j++;
        }
    }
}