// ***************************************
// * Carlos Corral-Williams | 1222280826 *
// ***************************************


#ifndef HEAP_H
#define HEAP_H

class TAG_ELEMENT{
    int num;
};
class TAG_HEAP{
    enum DataStructure {MaxHeap, MinHeap, DoubleHeap};
    int cap; // capacity of the (max_heap)/(min_heap)/(double_ended_heap)
    int len; // size of given heap
    ELEMENT **A; // array of pointers to ELEMENT obj (for max)
    ELEMENT **a // array of pointers to ELEMENT obj (for min)
    public:
        HEAP(adt);
        HEAP(int,int);
};


#endif //HEAP_H
