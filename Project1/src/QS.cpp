//
// Created by metzi on 9/17/22.
//
#include "QS.h"
/*TODO this needs to be finished*/
#include<iostream>
using namespace std;

int Partition(int *A, int start, int end) {
    int anchor = A[end];
    int partitionIndex = start;
    for (int i = start; i < end; i++){
        if(A[i]<=anchor)
        {
            swap(A[i],A[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(A[partitionIndex],A[end]);
    return partitionIndex;
}
void QuickSort(int *A, int start, int end)
{
    if(start < end){
        int partitionIndex = Partition(A,start,end);
        QuickSort(A,start,partitionIndex-1);
        QuickSort(A,partitionIndex+1,end);
    }
}
int main()
{
    int A[]={7,6,5,4,3,2,1,0};
    QuickSort(A,0,7);
    for(int i = 0; i < 8; i++) cout << A[i] << " ";
}