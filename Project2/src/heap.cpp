// ***************************************
// * Carlos Corral-Williams | 1222280826 *
// ***************************************

#include "heap.h"
using namespace std;

struct Element{
    int x;
};

HEAP::heap(ELEMENT *inputArr, int len, int adt, int cap){
    this->maxHeap = new ELEMENT[cap];
    this->minHeap = new ELEMENT[cap];
    for(int i = 0; i<len; i++){

    }
}
HEAP::heap(int cap, int adt, int len){

}

HEAP::heap(){

}

void HEAP::modArray(ELEMENT *inputArr,){

}
void HEAP::buildHeap(){

}

void HEAP::maxHeapify(int len, int pos){
    int big, to_left, to_right;
    big = pos, to_left = (2 * pos)+1, to_right = (2* pos)+2;
}

void HEAP::minHeapify(int len, int pos){
    int least, toLeft, toRight;
    least=pos, toLeft=(2*pos)+1, toRight=(2*pos)+2;
    if(toRight < len && minHeap[toRight] < minHeap[least]){
        least = toRight;
    }
    if(minHeap[toLeft] < minHeap[least] && toLeft < len){
        least = toLeft;
    }
    if(least != pos){
        swap(minHeap, pos, least);
        minHeapify(len, least);
    }
}
void HEAP::swap(){

}