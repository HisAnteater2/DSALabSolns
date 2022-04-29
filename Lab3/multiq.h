#define MAX 10
#include <stdio.h>
#include "que.h"
struct MultiQ{
    int num;
    struct Queue * q[MAX];
};
struct MultiQ* createMQ(int num); // creates a list of num Queues, each of which is empty.
struct MultiQ* addMQ(struct MultiQ * mq, struct Task  t); // adds t to the Queue corresponding to priority p in mq. Task includes a TaskID tid and a priority p.
struct Task nextMQ(struct MultiQ * mq); // returns the front of the non-empty Queue in mq with the highest priority.
struct MultiQ* delNextMQ(struct MultiQ * mq); // deletes the front of the non-empty Queue in mq with the highest priority; returns the modified MultiQ
int isEmptyMQ(struct MultiQ * mq); // tests whether all the Queues in mq are empty
int sizeMQ(struct MultiQ * mq); // returns the total number of items in the MultiQ
int sizeMQbyPriority(struct MultiQ * mq, Priority p); // returns the number of items in mq with the priority p.
struct Queue * getQueueFromMQ(struct MultiQ * mq, int p); // returns the Queue with priority p.