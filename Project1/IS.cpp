//
// Created by metzi on 9/17/22.
//
#include "IS.H"

void insertion_sort(A[],n,p){
    for i := 2 to n do
        key := A[i]
                //Insert A[i] into sorted
                j:=i-1
                        while j > 0 and A[j] > key do
                            A[j+1] := A[j]
                                    j := j-1
                                            A[j+1] := key

}
