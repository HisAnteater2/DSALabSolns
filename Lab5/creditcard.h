#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
struct cred{
    unsigned long cardno;
    char * bankcode;
    char * expirydate;
    char * fname;
    char * lname;
};
struct cred * credarray;
int i = 0;
int arrsize = 1000;
void read_file(FILE * fileptr);
void insertionSort(int n);