#include <stdlib.h>
#include "que.h"
struct Queue * newQ()
{
    struct Queue * queue = (struct Queue *) malloc (sizeof(struct Queue));
    return queue;
}
int isEmptyQ(struct Queue * q){
    if((q -> count == 0) && (q -> head == NULL) && (q -> tail == NULL))
    return 1;
    return 0;
}
struct Queue * delQ(struct Queue * q){
    if(!isEmptyQ(q)){
        if((q -> head) -> next != NULL){
        struct node * temp= (q -> head) -> next;
        free(q -> head);
        q -> head = temp;
        }
        else{
            free(q -> head);
            q -> head = NULL;
            q -> tail = NULL;
        }
        q -> count --;
    }
    return q;
}
Element front(struct Queue * q){
    return (q -> head) -> element;
}
struct Queue * addQ(struct Queue * q, Element e){
    struct node * nd = (struct node *) malloc (sizeof(struct node));
    nd -> element = e;
    if(!isEmptyQ(q))
    (q -> tail) -> next = nd;
    else
    q -> head = nd;
    q -> tail = nd;
    q -> count ++;
    return q;
}
int lengthQ(struct Queue * q){
    return q -> count;
}