//
// Created by metzi on 9/17/22.
//
/*TODO integrate this given code for main, after that start by getting functionality on a makefile w/ args to utilize
 * IS.h/IS.cpp first, then MS, then QS.*/
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
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
    FILE *fp1, *fp2;
    int n, v1, v2, v3; float x; double y;
    if (argc < 3){
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit (1);
    }
    fp1 = fopen(argv[1], "r");
    if (fp1 == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit (1);
    }
    fp2 = fopen(argv[2], "w");
    if (fp2 == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[2]);
        exit (1);
    }
    v1=fscanf(fp1, "%d", &n); v2=fscanf(fp1, "%f", &x); v3=fscanf(fp1, "%lf", &y);
    fprintf(fp2, "v1=%d, v2=%d, v3=%d\n", v1, v2, v3);
    fprintf(fp2, "n=%d, n=%4d\n", n, n);
    fprintf(fp2, "x=%f, x=%8.3f\n", x, x);
    fprintf(fp2, "y=%lf, y=%8.3lf\n", y, y);
    fclose(fp1); fclose(fp2);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
    FILE *fp;
    int i, n, *A;
    fp = fopen("INPUT.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: cannot open file INPUT.txt\n");
        exit (1);
    }
    fscanf(fp, "%d", &n);
    A = (int *) malloc(n*sizeof(int));
    if (A == NULL) {
        fprintf(stderr, "Error: cannot allocate memory\n");
        exit (1);
    }
    for (i=0; i<n; i++) fscanf(fp, "%d", &A[i]);
    for (i=0; i<n-1; i++) printf("%d ", A[i]); printf("%d\n", A[n-1]);
    free(A);
    return 0;
}