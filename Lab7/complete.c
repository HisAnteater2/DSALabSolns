#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

struct employee{
    int empID;
    char * name;
};

struct rtime{
    double IStime;
    double QStime;
};

struct employee * emp_arr;

void fusionsort(struct employee * earr, int len, int S){
    iterative_quicksort(earr, len, S);
    iterative_insertionsort(earr, len);
}
void iterative_insertionsort(struct employee * earr, int len){
    int i, j; struct employee key;
    for( i = 1; i < len; i++){
        key = earr[i];
        for(j = i-1; j>=0 && earr[j].empID > key.empID; j--){
            earr[j+1] = earr[j];
        }
        earr[j+1] = key;
    }
}
void iterative_quicksort(struct employee * earr, int len, int S){
    if(S < 1)
    S = 1;
    int stack[len];
    int l = 0;
    int r = len - 1;
    int head = -1;

    stack[++head] = l;
    stack[++head] = r;

    int p; int i, j; struct employee t;

    while(head >= 0)
    {
        r = stack[head--];
        l = stack[head--];
        i = l - 1;
        p = r;
        for( j = l; j < r; j++){
            if(earr[j].empID <= earr[p].empID){
                i++;
                t = earr[i];
                earr[i] = earr[j];
                earr[j] = t;
            }
        }
        t = earr[i+1];
        earr[i+1] = earr[r];
        earr[r] = t;
        p = i + 1;
        if (p - l > S)
        { 
            stack[++head] = l; 
            stack[++head] = p - 1; 
        } 
        if (r - p > S)
        { 
            stack[++head] = p + 1; 
            stack[++head] = r; 
        } 
    }
}
struct rtime testRun(struct employee * earr, int len){
    struct timeval t1, t2;
    double elapsedTime;
    struct rtime tt;
    struct employee * earr1 = (struct employee *) malloc(len*sizeof(struct employee));
    struct employee * earr2 = (struct employee *) malloc(len*sizeof(struct employee));
    for(int i = 0; i<len; i++){
        earr1[i].name = earr[i].name;
        earr2[i].name = earr[i].name;
        earr1[i].empID = earr[i].empID;
        earr2[i].empID = earr[i].empID;
    }
    gettimeofday(&t1, NULL);
    iterative_insertionsort(earr1, len);
    gettimeofday(&t2, NULL);
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
    tt.IStime = elapsedTime;
    gettimeofday(&t1, NULL);
    iterative_quicksort(earr2, len, 1);
    gettimeofday(&t2, NULL);
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
    tt.QStime = elapsedTime;
    free(earr1);
    free(earr2);
    return tt;
}

int estimateCutoff(struct employee * earr, int len){
    int min =5;
    int max = len;
    int mid;
    struct rtime tt1, tt2, tt;
    tt1 = testRun(earr, min);
    tt2 = testRun(earr, max);
    printf("For %d cases, IS time = %lfms and QS time = %lfms\n", min, tt1.IStime, tt1.QStime);
    printf("For %d cases, IS time = %lfms and QS time = %lfms\n", max, tt2.IStime, tt2.QStime);
    do{
        mid = (min + max)/2;
        tt = testRun(earr, mid);
        printf("For %d cases, IS time = %lfms and QS time = %lfms\n", mid, tt.IStime, tt.QStime);
        if(tt.IStime < tt.QStime)
            min = mid;
        else
            max = mid;
    }while(min < max);
    return mid;
}

int main(int argc, char *argv[])
{
    struct timeval t1, t2;
    double elapsedTime;
    FILE * fileptr = fopen(argv[1], "r");
    int len = atoi(argv[1]);
    emp_arr = (struct employee *) malloc(len*sizeof(struct employee));
    int i = 0;
    while(!feof(fileptr))
    {
        emp_arr[i].name = (char *) malloc(10*sizeof(char));
        fscanf(fileptr, "%s %d\n", emp_arr[i].name, &emp_arr[i].empID);
        i++;
    }
    fclose(fileptr);
    int mid = estimateCutoff(emp_arr, len);
    printf("Cutoff is at %d\n", mid);
    gettimeofday(&t1, NULL);
    fusionsort(emp_arr, len, mid);
    gettimeofday(&t2, NULL);
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
    printf("%lfms is the time taken by fusion sort\n", elapsedTime);
}