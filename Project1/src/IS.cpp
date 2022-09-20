//
// Created by metzi on 9/17/22.
//
/*TODO this needs to be finished*/
#include "IS.h"
#include <iostream>
using namespace std;

void InsertionSort::insertion_sort(int A[], int n) {}{
    for (int i = 1; i < n; i++) {
        int place_holder = A[i];
        int y = i - 1;
        do {
            A[y + 1] = A[y];
            y--;}
        while (y >= 0 and place_holder < A[y]);
        A[y+1]=place_holder;
        }
    };

int main(){

    int unsorted_array[6] = {1,2,3,4,5,6};
    int size = sizeof(unsorted_array);
    insertion_sort(unsorted_array,size);
    for(int i = 1; i < size; i++){
        std::cout << unsorted_array[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}