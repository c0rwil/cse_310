// ***************************************
// * Carlos Corral-Williams | 1222280826 *
// ***************************************
// STD imports
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <float.h>
#include <string.h>
// CUSTOM imports
#include "min-heap.h"
#include "graph-algorithms.h"

using namespace std;

int main(int argc, char *argv[]) {
    int previousSource = -1;
    int previousDestination = -1;
    ifstream heapFromTxt;
    string cmds;
    string previousCmds = "";
    string err0 = "Usage: ./PJ3 <GraphType> <InputFile>";

    if (argc < 3 || argc > 3) {
        cerr << err0;
        exit(0);
    }

    string graphType = argv[1];
    if (!(graphType == "Directed" || graphType == "Undirected")) {
        cerr << err0;
        exit(0);
    }
    heapFromTxt.open(argv[2]);
    int vertCount, edgeCount;
    Element *arr;
    Edge **adj;
    if (heapFromTxt.is_open()) {
        heapFromTxt >> vertCount;
        heapFromTxt >> edgeCount;
        vertCount++;
        arr = new Element[vertCount];
        adj = new Edge*[vertCount];
        for (int i = 0; i < vertCount; i++) {
            Element elem;
            elem.key = FLT_MAX;
            elem.posMin = i;
            elem.posMax = i;
            elem.pi = -1;
            elem.index = i;
            arr[i] = elem;
            adj[i]= NULL;
        }
        for (int i = 0; i < edgeCount; i++) {
            Edge *edge = new Edge;
            int edgeIndex;
            heapFromTxt >> edgeIndex;
            heapFromTxt >> edge->u;
            heapFromTxt >> edge->v;
            heapFromTxt >> edge->w;
            edge->nextEdge = adj[edge->u];
            adj[edge->u] = edge;
            if(graphType=="Undirected"){
                Edge* undirectedEdge = new Edge;
                undirectedEdge->u = edge->v;
                undirectedEdge->v = edge->u;
                undirectedEdge->w= edge->w;
                undirectedEdge->nextEdge = adj[edge->v];
                adj[edge->v]= undirectedEdge;
            }
        }
    }
    else {
        cerr << err0;
        heapFromTxt.close();
        exit(0);
    }
    heapFromTxt.close();

    int empty = 0;
    HEAP heap(2,empty,vertCount);

    while(true)
    {
        getline(cin,cmds);
        //stop program
        if(cmds == "Stop"){
            delete[]arr;
            delete[]adj;
            exit(0);
        }
        // print adjacency list
        else if(cmds == "PrintADJ") {
            for (int x = 1; x < vertCount; x++) {
                fprintf(stdout,"ADJ[%d]:",x);
                fprintf(stdout, "-->[%d %d: %4.2f]", adj[x]->u, adj[x]->v, adj[x]->w);
                Edge *temp = adj[x]->nextEdge;
                while(temp!=NULL){
                    fprintf(stdout, "-->[%d %d: %4.2f]", temp->u, temp->v, temp->w);
                    temp = temp->nextEdge;
                }
                fprintf(stdout,"\n");
            }
        }
        else if(cmds.substr(0,12) == "SingleSource"){ // S I N G L E S O U R C E
            int selection = cmds.find(" ",11);
            if(selection ==-1){
                cout <<err0;
                continue;
            }
            int source = stoi(cmds.substr(12,selection));
            // initialize single source
            for(int i = 1; i<vertCount; i++){
                arr[i].key = FLT_MAX;
                arr[i].pi = -1;
            }
            arr[source].key = 0;
            heap.elementInsert(arr[source]);
            while(true){
                Element temp = heap.extractMinElement();
                if(temp.posMin==-1){
                    break;
                }
                Edge *tempEdge = adj[temp.index];
                while(tempEdge!= NULL){
                    if(arr[tempEdge->v].key > arr[tempEdge->u].key + tempEdge->w){
                        arr[tempEdge->v].key = arr[tempEdge->u].key + tempEdge->w;
                        arr[tempEdge->v].pi = tempEdge->u;
                        heap.elementInsert(arr[tempEdge->v]);
                    }
                    tempEdge = tempEdge->nextEdge;
                }
            }
            previousCmds = cmds.substr(0,12);
            previousSource = source;
        }
        else if(cmds.substr(0,10)=="SinglePair"){
            int selectionSrcIndex= cmds.find(" ", 11);
            if(selectionSrcIndex==-1){
                cout << err0;
                continue;
            }
            int source = stoi(cmds.substr(10,selectionSrcIndex));
            int destination;
            try{
                destination = stoi(cmds.substr(selectionSrcIndex,cmds.length()));
            }
            catch(const invalid_argument&){
                cout << err0;
                continue;
            }
            previousSource= source;
            previousDestination=destination;
            previousCmds = cmds.substr(0,10);

            // initialize single source
            for(int i = 1; i<vertCount; i++){
                arr[i].key = FLT_MAX;
                arr[i].pi = -1;
            }
            arr[source].key = 0;
            heap.elementInsert(arr[source]);
            while(true){
                Element temp = heap.extractMinElement();
                if(temp.posMin==-1 || temp.index == destination){
                    break;
                }
                Edge *tempEdge = adj[temp.index];
                while(tempEdge!= NULL){
                    if(arr[tempEdge->v].key > arr[tempEdge->u].key + tempEdge->w){
                        arr[tempEdge->v].key = arr[tempEdge->u].key + tempEdge->w;
                        arr[tempEdge->v].pi = tempEdge->u;
                        heap.elementInsert(arr[tempEdge->v]);
                    }
                    tempEdge = tempEdge->nextEdge;
                }
            }
        }
        else if(cmds == "Vertex"){
            for (int x = 0; x < vertCount; x++) {
                if (x == vertCount-1) {
                    cout << "Element(" << x << ")" << " = " << arr[x].key << " " << arr[x].pi << "\n";
                    break;
                }
                else {
                    cout << "Element(" << x << ")" << " = " << arr[x].key << " " << arr[x].pi << "\n";
                }
            }
            cout << "\n";
        }
        else if(cmds.substr(0,9)=="PrintPath"){
            int selectionSrcIndex= cmds.find(" ", 10);
            if(selectionSrcIndex==-1){
                cout << err0;
                continue;
            }
            int source = stoi(cmds.substr(9,selectionSrcIndex));
            int destination;
            try{
                destination = stoi(cmds.substr(selectionSrcIndex,cmds.length()));
            }
            catch(const invalid_argument&){
                cout << err0;
                continue;
            }
           if((previousCmds=="SingleSource" && previousSource == source) || (previousCmds == "SinglePair"&& previousDestination == destination && previousSource == source)){
               if(arr[destination].key==FLT_MAX ){
                   fprintf(stdout, "There is no path from %d to %d.\n", source, destination);
                   continue;
               }
               int* stak= new int[vertCount];
               int currentIndex = 0;
               Element tempElem = arr[destination];
               stak[currentIndex]=destination;
               currentIndex++;
               while(tempElem.pi!=-1){
                   stak[currentIndex] = tempElem.pi;
                   currentIndex++;
                   tempElem = arr[tempElem.pi];
               }
               fprintf(stdout, "The shortest path from %d to %d is:\n", source, destination);
               int i = currentIndex-1;
               while(i>=0){
                   if(i==0){
                       tempElem=arr[stak[i]];
                       fprintf(stdout, "[%d:%8.2f].", tempElem.index, tempElem.key);

                   }
                   else{
                   tempElem = arr[stak[i]];
                   fprintf(stdout, "[%d:%8.2f]-->", tempElem.index, tempElem.key);
                   }
                   i = i-1;
               }
               fprintf(stdout, "\n");
           }

        }
        else if(cmds.substr(0,11)=="PrintLength"){
            int selectionSrcIndex= cmds.find(" ", 12);
            if(selectionSrcIndex==-1){
                cout << err0;
                continue;
            }
            int source = stoi(cmds.substr(11,selectionSrcIndex));
            int destination;
            try{
                destination = stoi(cmds.substr(selectionSrcIndex,cmds.length()));
            }
            catch(const invalid_argument&){
                cout << err0;
                continue;
            }
            if(!(previousCmds=="SingleSource" && previousSource == source) || (previousCmds == "SinglePair"&& previousDestination == destination && previousSource == source)){
                continue;
            }
            if(arr[destination].key==FLT_MAX){
                fprintf(stdout, "There is no path from %d to %d.\n", source, destination);
                continue;
            }
            fprintf(stdout, "The length of the shortest path from %d to %d is: %8.2f\n",
                    source, destination, arr[destination].key);


        }

        else{
            string errMsg="Invalid command.\n";
            cerr << errMsg;
            continue;
        }
    }
}
