// ***************************************
// * Carlos Corral-Williams | 1222280826 *
// ***************************************

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cstring>
#include "IS.h"
#include "MS.h"
#include "QS.h"
using namespace std;

int main(int argc, char *argv[]) {
    ifstream txt;
    int len, *inputArr, txtID, compareCount, anchor;
    int dispArr = 0, dispRes = 0,displayCompCount=0;
    txt.open("INPUT.txt");
    if (txt.is_open()){
        anchor = 0;
        txt >> dispRes;
        txt >> dispArr;
        txt >> len;
        inputArr = new int[len];
        while (txt >> txtID) {
            inputArr[anchor] = txtID;
            anchor++;
            }
        }
    else{
        cout << "Error: cannot open file " << "INPUT.txt" << "\n";
        exit(0);
        }
    txt.close();

    if (argc <= 2) {
        cout << "Usage: ./PJ1 alg flag\n"
                "       "
                "alg should be in {InsertionSort, MergeSort, QuickSort}\n"
                "       "
                "flag should be in {0, 1}\n";
        exit(0);
    }

    displayCompCount = atoi(argv[2]);

    if (displayCompCount > 1 || displayCompCount < 0) {
        cout << "Usage: ./PJ1 alg flag\n"
                "       "
                "alg should be in {InsertionSort, MergeSort, QuickSort}\n"
                "       "
                "flag should be in {0, 1}\n";
        exit(0);
    }

    if(strcmp(argv[1], "QuickSort") == 0) {
        QuickSort quickSort(inputArr, len, dispArr, dispRes, displayCompCount);
        compareCount = quickSort.sortThem();
    }
    else if (strcmp(argv[1], "MergeSort") == 0) {
        MergeSort mergeSort(inputArr, len, dispArr, dispRes, displayCompCount);
        compareCount = mergeSort.sortThem();
    }
    else if (strcmp(argv[1], "InsertionSort") == 0) {
        InsertionSort insertSort(inputArr, len, dispArr, dispRes, displayCompCount);
        compareCount = insertSort.sortThem();
    }
    else{
        cout << "Usage: ./PJ1 alg flag\n"
                "       "
                "alg should be in {InsertionSort, MergeSort, QuickSort}\n"
                "       "
                "flag should be in {0, 1}\n";
        exit(0);
    }
    cout << "Number of EWCs: " << compareCount << "\n";
    return 0;
    }
