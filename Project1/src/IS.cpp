//
// Created by metzi on 9/17/22.
//
/*TODO this needs to be finished*/
#include <iostream>
using namespace std;

void insertion_sort(int a[], int n)
{
    int i,j, k;
    for (i = 1; i < n; i++)
    {
        k = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > k)
        {
            cout<< a[j] << ">" << k <<endl;
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;

            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = k;
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
    int unsorted_array[] = {5,2,1,9,7,3};
    int size = (sizeof(unsorted_array) / sizeof(unsorted_array[0]));
    cout << size << endl;
    insertion_sort(unsorted_array,size);
    show_array(unsorted_array,size);
    return 0;
}