//
// Created by metzi on 9/17/22.
//
#include "QS.h"
/*TODO this needs to be finished*/
#include<iostream>

int Partition(int *A, int start, int end) {
    int anchor = A[end];
    int partition_pos= start;
    for (int i = start; i < end; i++){
        do { (swap(A[i], A[partition_pos])); partition_pos++;} while (A[i] <= anchor);
    }
}