#include "multiq.h"
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
struct MultiQ * loadData(FILE * f){
    struct MultiQ * mq = createMQ(10);
    while (!feof(f)){
        Element * temp = (Element *) malloc(sizeof(Element));
        int id, p;
        fscanf(f, "%d,%d", &id, &p);
        temp -> tid = id;
        temp -> p =  --p;
        addMQ(mq, *temp);
    }
    return mq;
}
struct MultiQ * testDel(struct MultiQ * mq, int num){
    for(int i = 0; i<num; i++){
        delNextMQ(mq);
    }
    return mq;
}
void main(int argc, char *argv[]){
    struct timeval t1, t2;
 double elapsedTime;
 // start timer
 gettimeofday(&t1, NULL);
    FILE * f = fopen(argv[1], "r");
    struct MultiQ * mq = loadData(f);
    testDel(mq, 10);
    printf("%d\n", sizeMQ(mq));
    printf("%d\n", sizeMQbyPriority(mq, 6));
    getQueueFromMQ(mq, 7);
    fclose(f);
 gettimeofday(&t2, NULL);
 // compute and print the elapsed time in millisec
 elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
 elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
 printf("Total time is %lf ms.\n", elapsedTime);

}