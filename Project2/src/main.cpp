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
ELEMENT *a;

void makeArr(int size){
    a = new ELEMENT[size];

}
int main(int argc, char *arg[]){
    ifstream commands;
    ifstream txt;
    int cap = 80;
    while(true){
        userIn =
    }
    int len, anchor, ID;
    ELEMENT inArr[cap];
    txt.open("HEAPifile.txt");
    if(txt.is_open()){
        anchor = 0;
        txt >> len;
        inArr* = makeArr(len);
//        inArr = new int[len];
        while(txt >> ID){
            inArr[anchor] == ID;
            anchor++;
        }
    }
    else{
        cout << "Error: cannot open file " << "HEAPifile.txt" << "\n";
        exit(0);
    }
    txt.close();

    if(argc >=4 || argc <= 0){
        cout << ""
    }
    commands.open("Commands");
    if(commands.is_open()){
        string cmd;
        while(getline(commands, cmd)){
            printf("%s",cmd.c_str());


        }
    }
    else{
        cout << "Error: cannot open file " << "Commands" << "\n";
        exit(0);
    }
    commands.close();

    return 0;
}
