// ***************************************
// * Carlos Corral-Williams | 1222280826 *
// ***************************************


#ifndef HEAP_H
#define HEAP_H

struct Element{
    int posMin;
    int posMax;
    int key;
    Element(){
        key = 0;
    }
};
//struct Heap {
//    int len, cap;
//    Element *maxHeap;
//    Element *minHeap;
//    Heap() {
//        maxHeap->key = 0;
//        len = 0;
//        cap = 0;
//    }
//};
//
//void Print(int adt, int *arr, int len);
//int rightNode(int x);
//int leftNode(int x);
//int parentNode(int x);
//
//void arrToHeap(int *arr, int cap, int len);
//void buildHeap(int adt, int *arr, int len);
//void buildMaxHeap(int *arr, int len);
//void buildMinHeap(int *arr, int len);
//
//void maxHeapify(int *arr, int x, int len);
//void minHeapify(int  *arr, int x, int len);
//
//void insertKey(int *arr, int &len, int value);
//
//void decreaseKey(int *arr, int x, int lower);
//void increaseKey(int *arr, int x, int higher); // TODO implement
//
//void extractMin(int adt, int* arr, int &len);
//void extractMax(int adt, int* arr, int &len);
//
//int deleteMinArr(int *arr, int pos); //todo
//int deleteMaxArr(int *arr, int pos); // todo

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

    void heap(int, int, int);
    void heap(int, int, int, Element *);
    ~HEAP();

    int parentNode(int x);
    int leftNode(int x);
    int rightNode(int x);
    void printHeap(Element *);
    void swap(Element *, int, int);

    // basic build heap
    void buildHeap();
    void insert(int);

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
    void modArray(Element *, int);
    void write();
    void print();
    void displayArr();
    void displayHeap(Element *);
    void del(int);
};


#endif //HEAP_H
