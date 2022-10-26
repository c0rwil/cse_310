// ***************************************
// * Carlos Corral-Williams | 1222280826 *
// ***************************************

#include "util.h"
#include <string.h>


using namespace std;

int Util::inputToADT(char **argv){
    if (strcmp(argv[1], "MaxHeap") == 0){
        return 1;
    }
    else if (strcmp(argv[1], "MinHeap") == 0){
        return 2;
    }
    else if (strcmp(argv[1], "DoubleHeap") == 0){
        return 3;
    }
    else{
        return 0;
    }
}

int Util::validateCap(char **argv){
    int strToInt = stoi(argv[2]);
    if(strToInt <= 0){
        return 0;
    }
    else{
        return strToInt;
    }
}
