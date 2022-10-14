// ***************************************
// * Carlos Corral-Williams | 1222280826 *
// ***************************************
#pragma once
#ifndef MS
#define MS
class MergeSort{
    void merge(int,int,int);
    void mergeSort(int,int);
    void displayArr(int, int);
    void display(int,int);
    void displayRes();
    bool sortComp(int *, int *, int, int);
public:
    int len, *arr, dispArr, dispRes, displayCompCount, compCount;
    int sortThem();
    MergeSort(int *, int, int, int, int);
};
#endif
