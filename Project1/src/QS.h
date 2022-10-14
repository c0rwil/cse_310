// ***************************************
// * Carlos Corral-Williams | 1222280826 *
// ***************************************
#pragma once
#ifndef QS
#define QS
class QuickSort{
    int partition(int, int);
    void displayArr(int, int);
    void displayRes();
    void display(int,int);
    void swap(int, int, int, int);
    void quickSort(int, int);
    void displayComparisons(int,int);
public:
    int len;
    int *arr;
    int dispArr;
    int dispRes;
    int displayCompCount;
    int compCount;
    int sortThem();
    QuickSort(int *, int, int, int, int);
};
#endif