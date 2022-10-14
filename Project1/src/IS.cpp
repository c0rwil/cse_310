// ***************************************
// * Carlos Corral-Williams | 1222280826 *
// ***************************************
#include <iostream>
#include "IS.h"
using namespace std;

// overloaded constructor, takes all but compCount and assigns
InsertionSort::InsertionSort(int *arr, int len, int dispArr, int dispRes, int displayCompCount)
{
    this->compCount=0;
    this->len=len;
    this->arr=arr;
    this->dispRes=dispRes;
    this->dispArr=dispArr;
    this->displayCompCount=displayCompCount;
}

void InsertionSort::display(){
    for (int x = 0; x < len; x++){
        cout << " " << arr[x];
    }
    cout << "\n";
}

// function to print out the contents of the array object
void InsertionSort::displayArr()
{
    if (dispArr==1)
    {
        cout << "A[" << 1 << ":" << len << "]:";
        display();
    }
}
// function to print contents after sorting
void InsertionSort::displayRes()
{
    if (dispRes==1)
    {
        cout << "A[" << 1 << ":" << len << "] after sorting:";
        display();
    }
}

// insertion_sort takes an array and size of the array and sorts the array using the insertion_sort algorithm
void InsertionSort::insertionSort()
{
    int valueAtIndex, i, anchor;
    int dispRes = 1;

    for (i = 0; i < len; i++)
    {
        anchor = i;
        valueAtIndex = arr[i];
        while (anchor> 0 && sortComp(arr[anchor-1],valueAtIndex))
        {
            arr[anchor] = arr[anchor - 1];
            displayArr();
            anchor= anchor-1;
        }
        arr[anchor] = valueAtIndex;
        if (dispRes++>1){
            displayArr();
        }
    }
}

int InsertionSort::sortThem()
{
    insertionSort();
    displayRes();

    return compCount;
}

// displays EWC thru out sorting of array if displayCompCount is not set to 0 / false
bool InsertionSort::sortComp(int x, int y)
{
    compCount++;
    if (displayCompCount == 1)
        cout << "EWC: " << x << " > " << y << "?"<< "\n";
    if(x > y){
        return 1;}
    else
        return 0;
}