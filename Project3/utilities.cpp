//
// Created by metzi on 11/29/22.
//

// standard imports:
// ----------------
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cctype>

// custom imports:
// ----------------
#include "min-heap.h
#include "utilities.h

using namespace std;

//    while(true){
//        getline(cin,cmds);
//
//        // reads heapfile.txt into an array
//        if(cmds == "Read"){
//        int len;
//        heapFromTxt.open("HEAPifile.txt");
//        if(heapFromTxt.is_open()){
//        heapFromTxt >> len;
//        if(len > cap){
//        string outputErr = "Size is bigger than capacity\n";
//        cerr << outputErr;
//        continue;
//        }
//        Element *arr = new Element[cap];
//        for(int x = 0; x < len ; x++){
//        heapFromTxt >> holdTxt;
//        Element holder;
//        holder.posMax = x;
//        holder.posMin = x;
//        holder.key = stoi(holdTxt);
//        arr[x] = holder;
//        }
//        heap.modArray(arr,len);
//        heap.buildHeap();
//        }
//        else{
//        string inaccessible = "Error: cannot open file HEAPifile.txt\n";
//        cerr << inaccessible;
//        heapFromTxt.close();
//        continue;
//        }
//        heapFromTxt.close();
//        }
//
//        // stop program
//        else if(cmds == "Stop"){
//        exit(0);
//        }
//
//        // write array into a heap
//        else if(cmds == "Write"){
//        heap.write();
//        }
//
//        // display the array
//        else if(cmds == "Print"){
//        heap.print();
//        }
//
//        // insert element
//        else if(cmds.substr(0,6) == "Insert"){
//        int index = 0;
//        if(cmds.length() <= 7){
//        string invalid = "Error: Invalid command\n";
//        cerr << invalid;
//        continue;
//        }
//        try{
//        index = stoi(cmds.substr(7,cmds.length()));
//        }
//        catch(const invalid_argument&){
//        string inval = "Error: Invalid command \n";
//        cerr << inval;
//        continue;
//        }
//        heap.insert(index);
//        }
//
//        // extract max from maxheap
//        else if(cmds == "ExtractMax"){
//        if(adt == 2){
//        string invalHeap = "Error: ExtractMax in a min heap or a null/empty heap\n";
//        cerr << invalHeap;
//        continue;
//        }
//        int most = heap.extractMax();
//        if(most == -55555){
//        cout << "\n";
//        continue;
//        }
//        cout << "ExtractMax: " << most << "\n";
//        }
//
//        // increase value of given element
//        else if(cmds.substr(0,11) == "IncreaseKey"){
//        if(adt == 2){
//        string errOut = "Error: IncreaseKey in a min heap or a null/empty heap\n";
//        cerr << errOut;
//        continue;
//        }
//
//        int selection = cmds.find(" ", 12);
//        if(selection == -1){
//        string posErr = "Invalid Position\n";
//        cout << posErr;
//        continue;
//        }
//        int pos = stoi(cmds.substr(11, selection));
//        int check;
//        try{
//        check = stoi(cmds.substr(selection,cmds.length()));
//        }
//        catch(const invalid_argument&){
//        string errCheck = "Invalid Key\n";
//        cout << errCheck;
//        continue;
//        }
//        heap.increaseKey(pos-1, check);
//        }
//
//        // extract minimum from minheap
//        else if(cmds == "ExtractMin"){
//        if(adt==1){
//        string minErr = "Error: ExtractMin in a max heap or a null/empty heap\n";
//        cerr << minErr;
//        continue;
//        }
//        int least = heap.extractMin();
//        if(least == 55555){
//        cout << "\n";
//        continue;
//        }
//        cout << "ExtractMin: " << least << "\n";
//
//        }
//
//        // decrease value of given element
//        else if(cmds.substr(0,11) == "DecreaseKey"){
//        if(adt==1){
//        string errDecrease = "Error: DecreaseKey in a min heap or a null/empty heap\n";
//        cerr << errDecrease;
//        continue;
//        }
//        int select = cmds.find(" ", 12);
//        if(select == -1){
//        string invalPos = "Invalid Position\n";
//        cout << invalPos;
//        continue;
//        }
//        int pos = stoi(cmds.substr(11,select));
//        int check;
//
//        try{
//        check = stoi(cmds.substr(select,cmds.length()));
//        }
//        catch(const invalid_argument&){
//        string err = "Invalid Key\n";
//        cout << err;
//        continue;
//        }
//        heap.decreaseKey(pos-1, check);
//
//        }
//
//        // invalid input
//        else{
//        string errMsg="Invalid Input, Try Again\n";
//        cout << errMsg;
//        }
//    }
//// behavior for reading user input
string commands(int *argv, int *argf, HEAP* h, FILE* f)
{
    string currentCMD;
    while(true)
    {
        scanf("%s", &currentCMD);

        // if space, tab or newline, disregard and continue
        if (currentCMD == ' ' || currentCMD == '\t' || currentCMD == '\n')
        {
            continue;
        }

        // stop
        if (tolower(currentCMD) == 'stop')
        {
            break;
        }

        // single pair
        if (tolower(currentCMD) == 'singlepair')
        {
//            scanf("%d", argv);
            break;
        }

        // single source
        if (tolower(currentCMD) == 'singlesource')
        {
            break;
        }

        // print path
        if (tolower(currentCMD) == 'printpath')
        {
            break;
        }

        // print length
        if (tolower(currentCMD) == 'printlength')
        {
            scanf("%d", v); scanf("%d", w);
            break;
        }

        // Increase key
        if (tolower(currentCMD) == 'printadj')
        {
            scanf("%d", argi); scanf("%d", argv); scanf("%d", argf);
            break;
        }

         // input is invalid
        else
        {
            printf("Invalid Command\n");
            break;
        }
    }

    return currentCMD;
}

