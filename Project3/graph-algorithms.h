//
// Created by metzi on 11/28/22.
//

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
#include "utilities.h"
#include "stack.h"

struct ELEMENT{
    int node;
    int key;
    int pi;
    ELEMENT(int n);
    ELEMENT(int n, int d, int p);
};

struct EDGE_LIST
{
    // edge
    int distance;
    int connectedIndex;
    EDGE_LIST* next;
    EDGE_LIST(int distance, int connectedIndex);
    EDGE_LIST(int distance, int connectedIndex, EDGE_LIST* next);
};

struct ADJ_LIST{
    EDGE_LIST* head;
    ADJ_LIST(EDGE_LIST* head);
};


#endif //CSE_310_GRAPH_ALGORITHMS_H
