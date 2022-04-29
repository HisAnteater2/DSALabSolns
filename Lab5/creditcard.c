#include "creditcard.h"
int * small_stack;
int * large_stack;
int main(int argc, char *argv[])
{
    struct timeval t1, t2;
    double elapsedTime;
    FILE * fileptr;
    for(int x= 0; x<atoi(argv[2]); x++){ 
    fileptr = fopen(argv[1], "r");
    read_file(fileptr);
    fclose(fileptr);
    }
    gettimeofday(&t1, NULL);
    int a = 1;
    small_stack = &a;
    insertionSort(i);
    gettimeofday(&t2, NULL);
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
    printf("Total time is %lf ms.\n", elapsedTime);
    printf("Stack Memory used is %d \n", (int) -(large_stack - small_stack));
    return 0;
}
void read_file(FILE * fileptr)
{   
    if(i==0){
    credarray = (struct cred *) malloc(arrsize*sizeof(struct cred));
    }
    while(!feof(fileptr))
    {
        if(i == arrsize)
        {
            arrsize+=1000;
            credarray = (struct cred *) realloc(credarray, arrsize*sizeof(struct cred));
        }
        credarray[i].bankcode = (char *) malloc(6*sizeof(char));
        credarray[i].expirydate = (char *) malloc(8*sizeof(char));
        credarray[i].fname = (char *) malloc(6*sizeof(char));
        credarray[i].lname = (char *) malloc(6*sizeof(char));
        fscanf(fileptr, "\"%lu,%[^,],%[^,],%[^,],%[^\"]\"\n", &credarray[i].cardno, credarray[i].bankcode, credarray[i].expirydate, credarray[i].fname, credarray[i].lname);
        i++;
    }
}
void insertInOrder(int n)
{
    struct cred last = credarray[n-1];
    int i = n-2;
    while(i>=0 && credarray[i].cardno  > last.cardno ){
        credarray[i+1] = credarray[i];
        i--;
    }
    credarray[i+1] = last;
    if (n == 2)
    {
        int b = 1;
        large_stack = &b;
    }
}
void insertionSort(int n)
{
    if(n<=1)
    return;
    insertionSort(n-1);
    insertInOrder(n);
}