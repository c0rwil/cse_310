//
// Created by metzi on 9/17/22.
//
/*TODO this needs to be finished*/
#pragma once
#ifndef CSE_310_IS_H
#define CSE_310_IS_H
static int InsertionSort(int A[], int n){
    int i,j,key;
    for (i = 1; i < n; i++)
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
        }
    return 0;
}
#endif //CSE_310_IS_H
