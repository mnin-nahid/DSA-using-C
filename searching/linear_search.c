#include <stdio.h>

int main()
{
    int array[] = {1, 3, 7, 2, 9, 4, 6, 8, 5, 0};
    int location = 0, search_value;
    printf("Enter the Search Velue : ");
    scanf("%d", &search_value);
    int length = sizeof(array) / sizeof(array[1]);

    while (array[location] != search_value && location <= length)
    {
        location++;
    }
    if (location == location + 1)
    {
        printf("%d Not Found !\n");
    }
    else
    {
        printf("%d is located on index : %d\n", location);
    }

    return 0;
}