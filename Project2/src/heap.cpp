// ***************************************
// * Carlos Corral-Williams | 1222280826 *
// ***************************************
#include <fstream>
#include <iostream>
#include "heap.h"


using namespace std;

HEAP::~HEAP(){
    delete[] maxArr, delete[] minArr;
}

HEAP::HEAP(int adt, int len, int cap){
    this->minArr = new Element[cap];
    this->maxArr = new Element[cap];
    this->adt = adt, this->cap = cap, this->len = len;
}
HEAP::HEAP(int adt, int len, int cap, Element *inArr){
    this->minArr = new Element[cap];
    this->maxArr = new Element[cap];
    this->adt = adt, this->cap=cap, this->len = len;
    for (int x = 0; x<len; x++){
        minArr[x] = inArr[x];
        maxArr[x] = inArr[x];
    }
}
int HEAP::rightNode(int x){
    return (2+(x*2));
}

int HEAP::leftNode(int x){
    return (1+(x*2));
}

int HEAP::parentNode(int x){
    return (x/2);
}

void HEAP::write(){
    ofstream output;
    string maxHeapStr = "MaxHeap: ";
    string minHeapStr = "MinHeap: ";
    string capaStr = "capacity=";
    string size = ", size=";
    output.open("HEAPofile.txt");
    if (output.is_open())
    {
        if (adt == 3)
        {
            output << capaStr << cap << size << len << "\n" << maxHeapStr;
            for (int x = 0; x < len; x++)
            {
                if (x == (len - 1))
                {
                    output << maxArr[x].key << "\n";
                    break;
                }
                output << maxArr[x].key << ", ";
            }
            output << minHeapStr;
            for (int x = 0; x < len; x++)
            {
                if (x == (len- 1))
                {
                    output << minArr[x].key << "\n";
                    break;
                }
                output << minArr[x].key << ", ";
            }
        }
        else if (adt == 1)
        {
            output << capaStr << cap << size << len <<"\n";
            output << maxHeapStr;
            for (int x = 0; x < len; x++)
            {
                if (x == (len - 1))
                {
                    output << maxArr[x].key << "\n";
                    break;
                }
                output << maxArr[x].key << ", ";
            }
        }
        else if (adt == 2)
        {
            output << capaStr << cap << size << len << "\n" << minHeapStr;
            for (int x = 0; x < len; x++)
            {
                if (x == (len-1))
                {
                    output << minArr[x].key << "\n";
                    break;
                }
                output << minArr[x].key << ", ";
            }
        }

    }
    else
    {
        fprintf(stderr, "Error: Cannot open file HEAPofile.txt\n");
    }
    output.close();
}

void HEAP::displayHeap(Element *arr){
    for(int x = 0; x < len; x++){
        if(x == len-1){
            cout << arr[x].key<< "\n";
            break;
        }
        cout << arr[x].key << ", ";
    }
}
void HEAP::displayArr(){
    if(adt == 2){
        if(len >=1){
            cout << "MinHeap: ";
            displayHeap(minArr);
        }
    }
    else if(adt == 1){
        if(len >=1){
            cout << "MaxHeap: ";
            displayHeap(maxArr);
        }
    }
    else if(adt == 3){
        if(len >= 1){
            cout << "MaxHeap: ";
            displayHeap(maxArr);
            cout << "MinHeap: ";
            displayHeap(minArr);
        }
    }

}

void HEAP::modArray(Element *input, int len) {
    delete[] minArr,delete[]maxArr;
    this->minArr = new Element[cap],this->maxArr = new Element[cap];
    this->len = len;
    for(int x = 0; x< len; x++){
        minArr[x] = input[x];
        maxArr[x]=input[x];
    }

}
void HEAP::buildMinHeap(){
    int half = len/2;
    for(int pos = half; pos > -1; pos--){
        minHeapify(len,pos);
    }
}
void HEAP::minHeapify(int len, int pos) {
    int l = leftNode(pos);
    int r = rightNode(pos);
    int least = pos;

    if (minArr[l].key < minArr[pos].key) {
        if (l < len) {
            least = l;
        }
    }
    if (minArr[r].key < minArr[least].key) {
        if (r < len) {
            least = r;
        }
    }
    if (least == pos)return;
    minArr[pos].posMin = least;
    int tmp1,tmp2;
    tmp1 = minArr[pos].posMax;
    maxArr[tmp1].posMin = least;
    minArr[least].posMin = pos;
    tmp2 = minArr[least].posMax;
    maxArr[tmp2].posMin = pos;
    swap(minArr[pos],minArr[least]);
    minHeapify(len,least);
}

void HEAP::maxHeapify(int len, int pos) {
    int tmp1,tmp2;
    int l = leftNode(pos);
    int r = rightNode(pos);
    int most = pos;
    if (maxArr[l].key > maxArr[most].key) {
        if (l < len) {
            most = l;
        }
    }
    if (maxArr[r].key > maxArr[most].key) {
        if (r < len) {
            most = r;
        }
    }
    if (most == pos)return;
    maxArr[pos].posMax = most;
    tmp1 = maxArr[pos].posMin;
    minArr[tmp1].posMax = most;
    maxArr[most].posMax = pos;
    tmp2 = maxArr[most].posMin;
    minArr[tmp2].posMax = pos;
    swap(maxArr[pos],maxArr[most]);
    maxHeapify(len,most);
}

void HEAP::buildMaxHeap(){
    int half = len/2;
    for(int pos = half; pos > -1; pos--){
        maxHeapify(len,pos);
    }
}

void HEAP::buildHeap(){
    if(adt ==3){
        buildMaxHeap();
        buildMinHeap();
    }
    else if(adt==2){
        buildMinHeap();
    }
    else{
        buildMaxHeap();
    }
}

void HEAP::print(){
    string capaStr = "capacity=";
    string size = ", size=";
    cout << capaStr << cap << size << len << "\n";
    displayArr();
}

void HEAP::insert(int value){
    int pos;
    if(len == cap){
        fprintf(stderr,"Error: Max Heap Size\n");
        return;
    }
    len++;
    pos = len -1;
    Element elem;
    elem.posMax=pos;
    elem.posMin=pos;
    if (adt != 1) {
        if (adt == 2) {
            elem.key = 55555;
            minArr[pos] = elem;
            decreaseKey(pos, value);
        } else if (adt == 3) {
            elem.key = -55555;
            maxArr[pos] = elem;
            elem.key = 55555;
            minArr[pos] = elem;
            increaseKey(pos, value);
            decreaseKey(pos, value);
        }
    } else {
        elem.key = -55555;
        maxArr[pos] = elem;
        increaseKey(pos, value);
    }
}

int HEAP::extractMin(){
    int least, end, index,tmp1,tmp2;
    if (len > 0) {
        least = minArr[0].key, index = minArr[0].posMax, end = len - 1;

        minArr[0].posMin = end;
        tmp1=minArr[0].posMax;
        maxArr[tmp1].posMin = end;
        minArr[end].posMin = 0;
        tmp2=minArr[end].posMax;
        maxArr[tmp2].posMin = 0;

        swap(minArr[0], minArr[end]);
        if (adt == 3) {
            maxArrDelete(index);
        }
        len--, minHeapify(len, 0);
        return least;
    }
    else {
        fprintf(stderr, "Error: heap currently empty");
        return 111111;
    }
}
int HEAP::extractMax(){
    int index, most, end,tmp1,tmp2;
    if (len > 0) {
        end = len-1,index=maxArr[0].posMin, most=maxArr[0].key;

        maxArr[0].posMax = end;
        tmp1 = maxArr[0].posMin;
        minArr[tmp1].posMax = end;
        maxArr[end].posMax = 0;
        tmp2 = maxArr[end].posMin;
        minArr[tmp2].posMax=0;

        swap(maxArr[0],maxArr[end]);
        if(adt==3){
            minArrDelete(index);
        }
        len--,maxHeapify(len,0);
        return most;
    }
    else {
        fprintf(stderr, "Error: heap currently empty");
        return -111111;
    }
}
void HEAP::decreaseKeyMax(int index, int value) {
    if (maxArr[index].key <= value || index >= len)return;
    maxArr[index].key = value;
    maxHeapify(len,index);
}

void HEAP::decreaseKeyMin(int index, int value) {
    int tmp1,tmp2;
    if (value >= minArr[index].key || index >= len) {
        fprintf(stderr, "Error: Invalid position or newKey in DecreaseKey\n");
    } else {
        minArr[index].key = value;
        while (minArr[index].key < minArr[(index - 1) / 2].key && index > 0) {
            minArr[index].posMin = ((index - 1) / 2);
            tmp1 = minArr[index].posMax;
            maxArr[tmp1].posMin = ((index - 1) / 2);
            minArr[((index - 1) / 2)].posMin = index;
            tmp2 = minArr[(index - 1) / 2].posMax;
            maxArr[tmp2].posMin = index;
            swap(minArr[index], minArr[(index - 1) / 2]);
            index = ((index - 1) / 2);
        }
    }
}

void HEAP::decreaseKey(int index, int value) {
    int x;
    if (adt != 2) {
        x = minArr[index].posMax;
        decreaseKeyMin(index, value);
        decreaseKeyMax(x, value);
    } else {
        decreaseKeyMin(index, value);
    }
}

void HEAP::increaseKey(int index, int value){
    int x;
    if (adt != 1) {
        x = maxArr[index].posMin;
        increaseKeyMax(index, value);
        increaseKeyMin(x, value);
    } else {
        increaseKeyMax(index, value);
    }
}

void HEAP::increaseKeyMin(int index, int value){
    if (index < len) {
        if (minArr[index].key < value) {
            minArr[index].key = value;
            minHeapify(len, index);
        }
    }
}

void HEAP::increaseKeyMax(int index, int value) {
    int tmp1, tmp2;
    if (value <= maxArr[index].key) {
        fprintf(stderr, "Error: Invalid position or newKey in IncreaseKey\n");
    } else {
        if (index < len) {
            maxArr[index].key = value;
            if (maxArr[index].key > maxArr[(index - 1) / 2].key) {
                while (index > 0) {
                    maxArr[index].posMax = ((index - 1) / 2);
                    tmp1 = maxArr[index].posMin;
                    minArr[tmp1].posMax = ((index - 1) / 2);
                    maxArr[(index - 1) / 2].posMax = index;
                    tmp2 = maxArr[(index - 1) / 2].posMin;
                    minArr[tmp2].posMax = index;
                    swap(maxArr[index], maxArr[(index - 1) / 2]);
                    index = (index - 1) / 2;
                }
            }
        }
    }
}

void HEAP::minArrDelete(int index) {
    int end;
    if (index >= len)return;
    end = len-1;
    minArr[index].posMin = end;
    maxArr[minArr[index].posMax].posMin = end;
    minArr[end].posMin = index;
    maxArr[minArr[end].posMax].posMin = index;
    swap(minArr[end],minArr[index]);

    if (minArr[index].key < minArr[(index - 1) / 2].key) {
        if (index <= len && index > 0) {
            while (index > 0 && minArr[index].key < minArr[(index - 1) / 2].key) {
                int tmp1,tmp2;
                minArr[index].posMin = (index - 1) / 2;
                tmp1=minArr[index].posMax;
                maxArr[tmp1].posMin = (index - 1) / 2;
                minArr[(index - 1) / 2].posMin = index;
                tmp2=minArr[(index-1)/2].posMax;
                maxArr[tmp2].posMin = index;

                swap(minArr[index], minArr[(index - 1) / 2]);
                index = (index - 1) / 2;
            }
        } else {
            minHeapify(len, index);
        }
    } else {
        minHeapify(len, index);
    }
}

void HEAP::maxArrDelete(int index){
    int end;
    if(index < len){
        end = len-1;
        maxArr[index].posMax = end;
        int tmp1,tmp2;
        tmp1 = maxArr[index].posMin;
        minArr[tmp1].posMax = end;
        maxArr[end].posMax = index;
        tmp2= maxArr[end].posMin;
        minArr[tmp2].posMax = index;
        swap(maxArr[end],maxArr[index]);

        if (index > 0 && index <= len) {
            if (maxArr[index].key > maxArr[(index - 1) / 2].key) {
                while (index > 0 && maxArr[index].key > maxArr[(index - 1) / 2].key) {
                    maxArr[index].posMax = (index - 1) / 2;
                    int tmp1, tmp2;
                    tmp1= maxArr[index].posMin;
                    minArr[tmp1].posMax = (index - 1) / 2;
                    maxArr[(index - 1) / 2].posMax = index;
                    tmp2=maxArr[((index-1)/2)].posMin;
                    minArr[tmp2].posMax = index;

                    swap(maxArr[index], maxArr[(index - 1) / 2]);
                    index = (index - 1) / 2;
                }
            } else {
                maxHeapify(len, index);
            }
        } else {
            maxHeapify(len, index);
        }
    }
}
