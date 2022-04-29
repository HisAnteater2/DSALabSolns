/* Stack.c */
#include <stdlib.h>
#include "Stack.h"
void push(struct linkedList * head, int ele){
    insertFirst(head, ele);
}
int pop(struct linkedList * head){
    int ret = (head -> first) -> element;
    deleteFirst(head);
    return ret;
}