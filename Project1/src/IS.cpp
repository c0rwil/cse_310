//
// Created by metzi on 9/17/22.
//
/*TODO this needs to be finished*/
#include <iostream>
using namespace std;

void swapThem(int A[] , int *B){
    int holder = *A;
    *A = *B;
    *B = holder;
}
void InsertionSort(int A[], int n)
{
    int i, x,key;
    for (i = 1; i < n; i++) {
        key = A[i];
        x = i-1;
        while (i > 0 && A[i] > key) {
            cout << A[x] << ">" << A[x] << endl;
            for (int i = 0; i < n; i++)
                cout << A[i] << " ";
            cout << endl;
            swapThem(&A[i+1],&A[i]);
            x = x - 1;
        }
        A[x + 1] = key;
        cout << A[x] << ">hhhhh" << key << endl;
    }
}
// A function to print an array of size n
void show_array(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main(){
    int unsorted_array[] = {0,2,5,1,4};
    int size = (sizeof(unsorted_array) / sizeof(unsorted_array[0]));
    InsertionSort(unsorted_array,size);
    show_array(unsorted_array,size);
    return 0;
}
// 1. a1(0) > a2(2)
// 2. a2(2) > a3(5)
// 3. a3(5) > a4(1)
// 4. a2(2) > a4(1)
// 5. a1(0) > a4(1)
// 6. a3(5) > a5(4)
// 7. a2(2) > a5(4)