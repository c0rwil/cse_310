// ***************************************
// * Carlos Corral-Williams | 1222280826 *
// ***************************************
#include <iostream>
#include "QS.h"
using namespace std;

// constructor for the quicksort
QuickSort::QuickSort(int *arr, int len, int dispArr, int dispRes, int displayCompCount)
{
    this->compCount=0;
    this->len=len;
    this->arr=arr;
    this->dispRes=dispRes;
    this->dispArr=dispArr;
    this->displayCompCount=displayCompCount;
}

// swap() takes an array and 2 indices that needs to be swapped
void QuickSort::swap(int x, int y, int begin, int last)
{
    int holder;
    holder = arr[x];
    arr[x] = arr[y];
    displayArr(begin, last);
    arr[y] = holder;
    displayArr(begin, last);
}

// partition function
int QuickSort::partition(int begin, int last)
{
    int posPartition = begin;
    int PivPoint = arr[last];

    for (int i = begin; i < last; i++)
    {
        displayComparisons(arr[i],PivPoint);
        if (arr[i] <= PivPoint)
        {
            swap(i, posPartition, begin, last);
            posPartition++;
        }
    }
    swap(posPartition, last, begin, last);
    return posPartition;
}

void QuickSort::displayArr(int start, int end)
{
    if (dispArr==1)
    {
        cout << "A[" << start + 1 << ":" << end + 1 << "]:";
        display(start,end);
    }
}
void QuickSort::displayRes(){
    if (dispRes==1)
    {
        cout << "A[" << 1 << ":" << len << "] after sorting:";
        display(0,len-1);
    }
}

void QuickSort::display(int first, int last){
    for (int i = first; i <= last; i++)
    {
        cout << " " << arr[i];
    }
    cout << "\n";
}
void QuickSort::displayComparisons(int x, int piv){
    compCount++;
    if (displayCompCount==1){
        cout << "EWC: " << x << " <= " << piv << "?" << "\n";
    }
}

int QuickSort::sortThem()
{
    quickSort(0, len - 1);
    displayRes();
    return compCount;
}

void QuickSort::quickSort(int begin, int last)
{
    if (begin < last)
    {
        int partitionPos = partition(begin, last);
        quickSort(begin, partitionPos - 1);
        quickSort(partitionPos + 1, last);
    }
}
