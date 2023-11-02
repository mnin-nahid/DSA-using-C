#include <stdio.h>

int main()
{
    char array[] = {'a', 'c', 'd', 'm', 'k', 'z', 'f', 'H', 'G', 'l', 'N', 'e', 'X'};
    int location = 0, attempt = 0; 
    char search_element;
    printf("enter search element : ");
    scanf("%c", &search_element);
    int length = sizeof(array)/sizeof(array[1]);
    while (array[location] != search_element && location <= length)
    {
        location++;
        attempt++;
    }
    if(location == length+1)printf("\t\t %c is not found!\n", search_element);
    else printf("\t\t %c is in ARRAY[%d] :: attempt - %d \n", search_element, location, attempt);
    
    return 0;
}