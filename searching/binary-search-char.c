#include <stdio.h>
int attempt = 0;

int binary_search(char array[], int search_value, int left, int right)
{
    attempt++;
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
void bubble_sort(char arr[], int length)
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

}

int main()
{
    char array[] = {'a', 'c', 'd', 'm', 'k', 'z', 'f', 'h', 'g', 'l', 'n', 'e', 'x'};
    int length = sizeof(array) / sizeof(array[1]);

    //sort the array
    bubble_sort(array, length);
    printf("Sorted Array : ");
    for (int i = 0; i < length; i++)
    {
        printf(" %c, ", array[i]);
    }
    printf("\n");
    
    //binary search
    char search_value;
    printf("Enter the search value : ");
    scanf("%c", &search_value);

    int search_index = binary_search(array, search_value, 0, length - 1);
    if (search_index != (-1))
    {
        printf("\t\t %c is in ARRAY[%d] :: attempt - %d\n", search_value, search_index, attempt);
    }
    else
    {
        printf("%c, not Found\n", search_value);
    }
    return 0;
}