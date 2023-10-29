#include <stdio.h>

int main()
{
    int temp ;
    int array[] = {3, 7, 9, 4, 6, 1, 8, 2, 5};
    for (int j = 0; j < 9; j++)
    {
        for (int i = 0; i < 9; i++)
        {
            if(array[i] > array[i+1]){
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        printf(" %d : %d \n",i, array[i]);
    }
    return 0;
}