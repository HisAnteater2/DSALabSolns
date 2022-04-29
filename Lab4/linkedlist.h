#include "exercise2.h"
#include <time.h>
struct node {
int element;
struct node * next;
};
/* structure of a linked list / head. It stores the count of number of elements
in the list and also a pointer link to the first node of the list. */
struct linkedList {
int count;
struct node * first;
struct node * last;
};
// function declarations
struct linkedList * createList(int N);
struct linkedList * createCycle(struct linkedList * Ls);