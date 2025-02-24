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

Element *a;
Util util;

int main(int argc, char *argv[]){
    int adt,cap;
    ifstream commands;
    ifstream heapFromTxt;
    string cmds, holdTxt;

    if(argc < 3 || argc > 3){
        string err0 = "Usage: ./PJ2 DataStructure Capacity\n"
                "       DataStructure should be in {MaxHeap, MinHeap, DoubleHeap}\n"
                "       Capacity must be a positive integer\n";
        cerr << err0;
        exit(0);
    }

    if(util.inputToADT(argv[1]) == 0)
    {
        string errText= "Usage: ./PJ2 DataStructure Capacity\n"
                        "       DataStructure should be in {MaxHeap, MinHeap, DoubleHeap}\n"
                        "       Capacity must be a positive integer\n";
        cerr << errText;
        exit(0);
    }
    adt = util.inputToADT(argv[1]);

    if(util.validateCap(argv[2]) == 0){
        string err2 ="Usage: ./PJ2 DataStructure Capacity\n"
                "       DataStructure should be in {MaxHeap, MinHeap, DoubleHeap}\n"
                "       Capacity must be a positive integer\n";
        cerr << err2;
        exit(0);
    }
    cap = util.validateCap(argv[2]);
    int empty = 0;
    HEAP heap(adt,empty,cap);
    while(true){
        getline(cin,cmds);

        // reads heapfile.txt into an array
        if(cmds == "Read"){
            int len;
            heapFromTxt.open("HEAPifile.txt");
            if(heapFromTxt.is_open()){
                heapFromTxt >> len;
                if(len > cap){
                    string outputErr = "Size is bigger than capacity\n";
                    cerr << outputErr;
                    continue;
                }
                Element *arr = new Element[cap];
                for(int x = 0; x < len ; x++){
                    heapFromTxt >> holdTxt;
                    Element holder;
                    holder.posMax = x;
                    holder.posMin = x;
                    holder.key = stoi(holdTxt);
                    arr[x] = holder;
                }
                heap.modArray(arr,len);
                heap.buildHeap();
            }
            else{
                string inaccessible = "Error: cannot open file HEAPifile.txt\n";
                cerr << inaccessible;
                heapFromTxt.close();
                continue;
            }
            heapFromTxt.close();
        }

        // stop program
        else if(cmds == "Stop"){
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

    // exit
    return 0;
}
