// ***************************************
// * Carlos Corral-Williams | 1222280826 *
// ***************************************

#include "heap.h"

using namespace std;

HEAP HEAP::heap(int len, int adt, int cap, Element *inputArr){

    this->maxHeap = new Element[cap];
    this->minHeap = new Element[cap];
    for(int i = 0; i<len; i++){

    }
}
HEAP HEAP::heap(int cap, int adt, int len){

}

HEAP HEAP::heap(){

}

void HEAP::modArray(Element *inputArr, int change){

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
    if(toRight < len && self.minHeap[toRight] < self.minHeap[least]){
        least = toRight;
    }
    if(self.minHeap[toLeft] < self.minHeap[least] && toLeft < len){
        least = toLeft;
    }
    if(least != pos){
        swap(self.minHeap, pos, least);
        minHeapify(len, least);
    }
}
void HEAP::swap(Element* b, int a, int z){

}