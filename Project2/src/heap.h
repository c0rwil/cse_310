// ***************************************
// * Carlos Corral-Williams | 1222280826 *
// ***************************************


#ifndef HEAP_H
#define HEAP_H

struct Element{
    int posMin;
    int posMax;
    int x;
};

class HEAP{
    // cap = capacity of the (max_heap)/(min_heap)/(double_ended_heap)
    // len = size of given heap
    // adt = typeOfHeap
    int cap, len, adt;

    Element *A; // array of pointers to ELEMENT obj (for max)
    Element *a; // array of pointers to ELEMENT obj (for min)

    void swap(Element *, int, int);
    void buildHeap(int);
    void printHeap(Element *);
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
    heap();
    heap(int,int,int);
    heap(Element *, int, int, int);

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
    void del(int);

};


#endif //HEAP_H
