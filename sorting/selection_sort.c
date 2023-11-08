#include<stdio.h>

int main(){
    int array[] = {5, 9, 7, 6, 4, 0,2, 3, 8, 1};
    int length = sizeof(array)/sizeof(array[1]);
    for(int i = 0; i <length-1; i++){
        int min_possision = i;
        for(int j = i+1; j < length; j++){
            if(array[i] < array[j]) min_possision = j;
            if(min_possision != j){
                int temp = array[i];
                array[i] = array[min_possision];
                array[min_possision] = temp;
            }
        }
    }

    //print the array
    for(int i = 0; i < length;i++){
        printf("%d, ", array[i]);
    }
    printf("\n");
}



























// #include<stdio.h>

// int main(){
//     int array[] = {5, 9, 7, 6, 4, 0,2, 3, 8, 1};
//     int length = sizeof(array)/sizeof(array[1]);
//     for(int i = 0; i< length -1; i++){
//         int min_pos = i;
//         for (int j = i + 1; j < length; j++){
//             if(array[j] < array[min_pos]) min_pos = j;
//             if(min_pos != i){
//                 int temp = array[i];
//                 array[i] = array[min_pos];
//                 array[min_pos] = temp;
//             }
//         }
//     }

//     for(int i = 0; i < length; i++){
//         printf("%d\t", array[i]);
//     }
//     printf("\n");
//     return 0;
// }