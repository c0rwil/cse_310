// ***************************************
// * Carlos Corral-Williams | 1222280826 *
// ***************************************
// STD imports
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdio.h>

// CUSTOM imports
#include "min-heap.h"
#include "utilities.h"

using namespace std;

Element *a;
Utilities util;

int main(int argc, char *argv[]){
    int adt;
    ifstream commands;
    ifstream heapFromTxt;
    string cmds, holdTxt;
    string err0 = "Usage: ./PJ3 <GraphType> <InputFile>";

    if(argc < 3 || argc > 3){
        cerr << err0;
        exit(0);
    }

    if(!(tolower(argv[1])) == "directed" || tolower(argv[1]) == "undirected"))
    {
        cerr << err0;
        exit(0);
    }
    int len;
    heapFromTxt.open(argv[2]);
    if(heapFromTxt.is_open()) {
        int vertCount, edgeCount;
        heapFromTxt >> vertCount;
        heapfromTxt >> edgeCount;
        ADJ list =ADJ_List(edgecount,vertCount);
    }
    else{
        cerr << err0;
        heapFromTxt.close();
        continue;
    }
    heapFromTxt.close();

    int empty = 0;
    //    HEAP heap(adt,empty,cap);
    while(true){
        getline(cin,cmds);
        // stop program
        if(tolower(cmds) == "stop"){
            exit(0);
        }
        // write array into a heap
        else if(cmds == "Write"){
            heap.write();
        }

            // display the array
        else if(cmds == "Print"){
            heap.print();
        }

            // insert element
        else if(cmds.substr(0,6) == "Insert"){
            int index = 0;
            if(cmds.length() <= 7){
                string invalid = "Error: Invalid command\n";
                cerr << invalid;
                continue;
            }
            try{
                index = stoi(cmds.substr(7,cmds.length()));
            }
            catch(const invalid_argument&){
                string inval = "Error: Invalid command \n";
                cerr << inval;
                continue;
            }
            heap.insert(index);
        }

            // extract max from maxheap
        else if(cmds == "ExtractMax"){
            if(adt == 2){
                string invalHeap = "Error: ExtractMax in a min heap or a null/empty heap\n";
                cerr << invalHeap;
                continue;
            }
            int most = heap.extractMax();
            if(most == -55555){
                cout << "\n";
                continue;
            }
            cout << "ExtractMax: " << most << "\n";
        }

            // increase value of given element
        else if(cmds.substr(0,11) == "IncreaseKey"){
            if(adt == 2){
                string errOut = "Error: IncreaseKey in a min heap or a null/empty heap\n";
                cerr << errOut;
                continue;
            }

            int selection = cmds.find(" ", 12);
            if(selection == -1){
                string posErr = "Invalid Position\n";
                cout << posErr;
                continue;
            }
            int pos = stoi(cmds.substr(11, selection));
            int check;
            try{
                check = stoi(cmds.substr(selection,cmds.length()));
            }
            catch(const invalid_argument&){
                string errCheck = "Invalid Key\n";
                cout << errCheck;
                continue;
            }
            heap.increaseKey(pos-1, check);
        }

            // extract minimum from minheap
        else if(cmds == "ExtractMin"){
            if(adt==1){
                string minErr = "Error: ExtractMin in a max heap or a null/empty heap\n";
                cerr << minErr;
                continue;
            }
            int least = heap.extractMin();
            if(least == 55555){
                cout << "\n";
                continue;
            }
            cout << "ExtractMin: " << least << "\n";

        }

            // decrease value of given element
        else if(cmds.substr(0,11) == "DecreaseKey"){
            if(adt==1){
                string errDecrease = "Error: DecreaseKey in a min heap or a null/empty heap\n";
                cerr << errDecrease;
                continue;
            }
            int select = cmds.find(" ", 12);
            if(select == -1){
                string invalPos = "Invalid Position\n";
                cout << invalPos;
                continue;
            }
            int pos = stoi(cmds.substr(11,select));
            int check;

            try{
                check = stoi(cmds.substr(select,cmds.length()));
            }
            catch(const invalid_argument&){
                string err = "Invalid Key\n";
                cout << err;
                continue;
            }
            heap.decreaseKey(pos-1, check);

        }

            // invalid input
        else{
            string errMsg="Invalid Input, Try Again\n";
            cout << errMsg;
        }
    }
