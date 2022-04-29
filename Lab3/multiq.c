#include <stdlib.h>
#include "multiq.h"
struct MultiQ * createMQ(int num){
    struct MultiQ * mq = (struct MultiQ *) malloc (sizeof(struct MultiQ));
    mq->num = num;
    for (int i = 0; i <num; i++){
        mq->q[i] = newQ();
    }
    return mq;
}
struct MultiQ * addMQ(struct MultiQ * mq, struct Task t){
    addQ(mq->q[t.p], t);
    return mq;
}
struct Task nextMQ(struct MultiQ * mq){
    for(int i = 0; i<mq->num; i++){
        if(!isEmptyQ(mq->q[i])){
            return ((mq->q[i])->head)->element;
        }
    }
}
struct MultiQ * delNextMQ(struct MultiQ * mq){
    if(!isEmptyMQ(mq)){
        delQ(mq->q[nextMQ(mq).p]);
    }
    return mq;
}
int isEmptyMQ(struct MultiQ * mq){
    for(int i = 0; i<mq->num; i++){
        if(!isEmptyQ(mq->q[i])){
            return 0;
        }
    }
    return 1;
}
int sizeMQ(struct MultiQ * mq){
    int ans = 0;
    for(int i = 0; i<mq->num; i++){
        ans+=lengthQ(mq->q[i]);
    }
    return ans;
}
int sizeMQbyPriority(struct MultiQ * mq, Priority p){
    return lengthQ(mq->q[p]);
}
struct Queue * getQueueFromMQ(struct MultiQ * mq, int p){
    return mq->q[p];
}