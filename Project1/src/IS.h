// ***************************************
// * Carlos Corral-Williams | 1222280826 *
// ***************************************
#pragma once
#ifndef IS
#define IS
class InsertionSort{
    int len, *arr, dispArr, dispRes, displayCompCount, compCount;
    bool sortComp(int, int);
    void displayArr();
    void displayRes();
    void display();
    void insertionSort();
public:
    int sortThem();
    InsertionSort(int *, int, int, int, int);
};
#endif