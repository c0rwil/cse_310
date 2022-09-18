//
// Created by metzi on 9/17/22.
//
/*TODO integrate this given code for main, after that start by getting functionality on a makefile w/ args to utilize
 * IS.h/IS.cpp first, then MS, then QS.*/
#include <stdio.h>
#include <stdlib.h>
#include "IS.cpp"

int main(int argc, char *argv[]){
    FILE *fp;
    int n, v1, v2, v3; float x; double y;

    printf("argc=%d\n", argc);
    for (int i=0; i<argc; i++){
        printf("The str value of argv[%d] is %s\n", i, argv[i]);
        printf("The int value of argv[%d] is %d\n\n", i, atoi(argv[i]));
    }
    if (argc < 3){
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit (1);
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit (1);
    }

    v1=fscanf(fp, "%d", &n); v2=fscanf(fp, "%f", &x); v3=fscanf(fp, "%lf", &y);
    fscanf(fp, "%d", &n);
    A = (int *) malloc(n*sizeof(int));
    if (A == NULL) {
        fprintf(stderr, "Error: cannot allocate memory\n");
        exit (1);
    }
    for (i=0; i<n; i++) fscanf(fp, "%d", &A[i]);
    for (i=0; i<n-1; i++) printf("%d ", A[i]); printf("%d\n", A[n-1]);
    free(A);
    fclose(fp);
    return 0;
}