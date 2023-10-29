#include<stdio.h>


int main(){
    char temp;
    char array[] = {'a', 'c', 'd', 'm', 'k', 'z', 'f', 'h', 'g', 'l', 'n', 'e', 'x'};
    int arr_size =(int) sizeof(array)/ sizeof(array[1]);
    char sorted_arr[arr_size];
    for(int i = 0; i < arr_size-1; i++){
        for (int j = i+1; j < arr_size; j++){
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    printf("%s\n", array);
    for(int i =0; i < arr_size; i++){
        printf("%d ", array[i]);
    }

    return 0;
}