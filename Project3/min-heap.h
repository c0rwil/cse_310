// ***************************************
// * Carlos Corral-Williams | 1222280826 *
// ***************************************
#ifndef CSE_310_MIN_HEAP_H
#define CSE_310_MIN_HEAP_H
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <stdio.h>
//#include "stack.h"
#include "graph-algorithms.h"



class HEAP {
public:
    // cap = capacity of the (max_heap)/(min_heap)/(double_ended_heap)
    // len = size of given heap
    // adt = typeOfHeap
    int cap, len, adt, *heapArr;

    //element arrays
    Element *maxArr; // array of pointers to ELEMENT obj (for max)
    Element *minArr; // array of pointers to ELEMENT obj (for min)

    //constructors

    HEAP(int, int, int);
    HEAP(int, int, int, Element*);
    ~HEAP();

    int parentNode(int x);
    int leftNode(int x);
    int rightNode(int x);
    void printHeap(Element *);

    // basic build heap
    void buildHeap();
    void insert(int);
    void elementInsert(Element);
    Element extractMinElement();

    void buildMinHeap();
    void buildMaxHeap();

    void minHeapify(int, int);
    void minHeapInsert(int);
    void minArrDelete(int);

    void maxHeapify(int, int);
    void maxHeapInsert(int);
    void maxArrDelete(int);
    // increase Element in heaps
    void increaseKey(int, int);
    void increaseKeyMin(int, int);
    void increaseKeyMax(int, int);
    // decrease Element in heap
    void decreaseKey(int, int);
    void decreaseKeyMin(int, int);
    void decreaseKeyMax(int, int);

    // extract min/max from heap
    int extractMin();
    int extractMax();

    // helpers
    void modArray(Element*, int);
    void write();
    void print();
    void displayArr();
    void displayHeap(Element*);
    void del(int);
};


#endif //HEAP_H
