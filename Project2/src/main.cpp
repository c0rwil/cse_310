// ***************************************
// * Carlos Corral-Williams | 1222280826 *
// ***************************************

// STD imports
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdio.h>

// CUSTOM imports
#include "heap.h"
#include "util.h"

using namespace std;
TAG_ELEMENT *a;

void makeArr(int size){
    a = new TAG_ELEMENT[size];
}
int main(){
    ifstream txt;
    string commands;
    int len;
    txt.open("COMMANDS");
    if(txt.is_open()){
        txt >> commands;
    }
}
