#include<stdio.h>

int main(){
    int array[] = { 2, 8, 3, 1, 2, 7, 8, 9, 3, 2, 4};
    int length = sizeof(array)/sizeof(array[1]);

    //find the max number for frequency
    int max_num = array[0];
    for(int i = 0; i< length;i++){
        if(max_num < array[i]) max_num = array[i];
    }

    //frequency array
    int frequency[10] = {0};
    for(int i = 0; i < length; i++){
        frequency[array[i]]++;
    }
    
    for(int i =0; i <= length; i++){
        frequency[i] = frequency[i]+frequency[i-1];
    }

    int output[length];
    for (int i = length-1; i >= 0; i--)
    {
        output[--frequency[array[i]]] = array[i];
    }
    
    //print array
    for(int i = 0; i < length; i++){
        printf("%d \n", output[i]);
    }
    return 0;
}