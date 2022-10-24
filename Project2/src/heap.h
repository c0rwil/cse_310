// ***************************************
// * Carlos Corral-Williams | 1222280826 *
// ***************************************


#ifndef HEAP_H
#define HEAP_H

class ELEMENT{
    ELEMENT(int);

    int key;
};
class HEAP{
    enum DataStructure {MaxHeap, MinHeap, DoubleHeap};
    // cap = capacity of the (max_heap)/(min_heap)/(double_ended_heap)
    // len = size of given heap
    // adt = typeOfHeap
    int cap, len, adt;

    ELEMENT *A; // array of pointers to ELEMENT obj (for max)
    ELEMENT *a; // array of pointers to ELEMENT obj (for min)

    void swap(ELEMENT *, int, int);
    void buildHeap(int);
    void printHeap(ELEMENT *);
    void buildMinHeap();
    void minHeapify(int, int);
    void minHeapInsert(int);
    void minKill(int);
    void maxHeapify(int, int);
    void maxHeapInsert(int);
    void buildMaxHeap();
    void maxKill(int);

public:
    // heap constructor
    heap(ELEMENT *, int, int, int);
    heap(int,int,int);
    heap();

    // basic build heap
    void buildHeap();
    void insert();

    // increase Element in heaps
    void increaseKey(int,int);
    void minIncreaseKey(int,int);
    void maxIncreaseKey(int,int);

    // decrease Element in heap
    void decreaseKey(int,int);
    void minDecreaseKey(int,int);
    void maxDecreaseKey(int,int);

    // extract min/max from heap
    int extractMin();
    int extractMax();

    // helpers
    void modArray(ELEMENT *, int);
    void write();
    void print();
    void printArray();
    void delete(int);

};


#endif //HEAP_H
