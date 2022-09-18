//
// Created by metzi on 9/17/22.
//
#include <stdio.h>
#include <stdlib.h>
#include "IS.cpp"

int main(int argc, char *argv[]){
    printf("argc=%d\n", argc);
    for (int i=0; i<argc; i++){
        printf("The str value of argv[%d] is %s\n", i, argv[i]);
        printf("The int value of argv[%d] is %d\n\n", i, atoi(argv[i]));
    }
    return 0;
}