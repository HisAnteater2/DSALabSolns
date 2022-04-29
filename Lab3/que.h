#include <stdio.h>
typedef int TaskID;
typedef int Priority;
struct Task {
TaskID tid;
Priority p;
};
typedef struct Task Element;
struct node {
Element element;
struct node * next;
};
struct Queue {
int count;
struct node * head;
struct node * tail;
};
struct Queue * newQ(); // returns an empty Queue
int isEmptyQ(struct Queue * q); // tests whether q is empty
struct Queue * delQ(struct Queue * q); // deletes the element from the front of the Queue; returns the modified Queue
Element front(struct Queue * q); // returns the element from the front of the Queue;
struct Queue * addQ(struct Queue * q , Element e); // adds e to the rear of the Queue; returns the modified Queue
int lengthQ(struct Queue * q); // returns the length of the Queue