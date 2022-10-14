// ***************************************
// * Carlos Corral-Williams | 1222280826 *
// ***************************************
#include <iostream>
#include "MS.h"
using namespace std;

// constructor for merge sort
MergeSort::MergeSort(int *arr, int len, int dispArr, int dispRes, int displayCompCount)
{
    this->compCount=0;
    this->len=len;
    this->arr=arr;
    this->dispRes=dispRes;
    this->dispArr=dispArr;
    this->displayCompCount=displayCompCount;
}

// mergeSort function, breaks problem into smaller parts then merges after recursive calls to self
void MergeSort::mergeSort(int i, int final)
{
    if (i >= final)
        return;

    int midPoint = i + (final - i) / 2;
    mergeSort(i, midPoint);
    mergeSort(midPoint + 1, final);
    merge(i, midPoint, final);
}

//merge function, sorts the subArrs and merges them
void MergeSort::merge(int begin, int midPoint, int last)
{
    int arrIndex, arrIndexA, arrIndexB;

    int arrALen = midPoint - begin + 1;
    int arrBLen = last - midPoint;

    int *arrA = new int[arrALen];
    int *arrB = new int[arrBLen];

    for (arrIndexA = 0; arrIndexA < arrALen; arrIndexA++)
        arrA[arrIndexA] = arr[begin + arrIndexA];
    for (arrIndexB = 0; arrIndexB < arrBLen; arrIndexB++)
        arrB[arrIndexB] = arr[midPoint + arrIndexB + 1];

    arrIndex = begin;
    arrIndexA = 0;
    arrIndexB = 0;
    while (arrIndexA < arrALen && arrIndexB < arrBLen)
    {
        if (sortComp(arrA, arrB, arrIndexA, arrIndexB))
        {
            arr[arrIndex] = arrA[arrIndexA];
            displayArr(begin, last);
            arrIndexA++;
        }
        else
        {
            arr[arrIndex] = arrB[arrIndexB];
            displayArr(begin, last);
            arrIndexB++;
        }
        arrIndex++;
    }
    while (arrIndexA < arrALen)
    {
        arr[arrIndex] = arrA[arrIndexA];
        displayArr(begin, last);
        arrIndex++;
        arrIndexA++;
    }
    while (arrIndexB < arrBLen)
    {
        arr[arrIndex] = arrB[arrIndexB];
        displayArr(begin, last);
        arrIndex++;
        arrIndexB++;
    }
    //free memory post-use
    delete[] arrA;
    delete[] arrB;
}

// prints EWC thru out sorting if displayCompCount not 0/false
bool MergeSort::sortComp(int *arrA, int *arrB, int arrAIndex, int arrBIndex)
{
    this->compCount = compCount + 1;
    if (displayCompCount==1)
        cout << "EWC: " << arrA[arrAIndex] << " <= " << arrB[arrBIndex] << "?"<< "\n";
    if (arrA[arrAIndex] <= arrB[arrBIndex])
    {
        return 1;
    }
    else{
        return 0;
    }
}
// displays array if dispArr not 0/false
void MergeSort::displayArr(int begin, int last)
{
    if (dispArr == 1)
    {
        cout << "A[" << begin + 1 << ":" << last + 1 << "]:";
        display(begin,last);
    }
}
// displays resulting array post-sort if dispRes not set to 0/false
void MergeSort::displayRes()
{
    if (dispRes==1)
    {
        cout << "A[" << 1 << ":" << len << "] after sorting:";
        display(0,len-1);
    }
}

void MergeSort::display(int first, int last) {
    for (int i = first; i <= last; i++) {
        cout << " " << arr[i];
    }
    cout << "\n";
}

int MergeSort::sortThem()
{
    mergeSort(0, len - 1);
    displayRes();

    return compCount;
}