// ***************************************
// * Carlos Corral-Williams | 1222280826 *
// ***************************************
#ifndef CSE_310_GRAPH_ALGORITHMS_H
#define CSE_310_GRAPH_ALGORITHMS_H

// standard imports:
// -----------------
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>

// custom imports:
// -----------------
#include "min-heap.h"


class Element {
public:
    int index;
    float key;
    int pi;
    int posMin;
    int posMax;
};

class Edge{
public:
    int u, v;
    float w;
    Edge *nextEdge;
};
class Adjacency_List{
public:
    Edge* head;
    Adjacency_List(Edge* h);
};


#endif //CSE_310_GRAPH_ALGORITHMS_H
