#include <stdio.h>
int binary_search(int array[], int search_value, int left, int right);
int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 34, 56, 93};
    int length = sizeof(array) / sizeof(array[1]);

    int search_value;
    printf("Enter the search value : ");
    scanf("%d", &search_value);

    int search_index = binary_search(array, search_value, 0, length - 1);
    if (search_index != (-1))
    {
        printf("we found %d, in %d index", search_value, search_index);
    }
    else
    {
        printf("%d, not Found\n", search_value);
    }
    return 0;
}

int binary_search(int array[], int search_value, int left, int right)
{
    if (left > right)
    {
        return -1;
    }
    else
    {
        int mid = left + (right - left) / 2;
        if (array[mid] == search_value)
        {
            return mid;
        }
        else if (search_value < array[mid])
        {
            return binary_search(array, search_value, left, mid - 1);
        }
        else
        {
            return binary_search(array, search_value, mid + 1, right);
        }
    }
}