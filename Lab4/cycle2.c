#include "cycle.h"

int testCyclic(struct linkedList * Ls){
    if(Ls -> count < 3){
        return 0;
    }
    struct node * ptr; struct node * temp;
    ptr = Ls -> first;
    while(ptr != NULL){
        temp = ptr;
        ptr = ptr->next;
        ptr -> next = temp;
        if(ptr == (Ls -> first)){
            return 1;
        }
    }
    return 0;
}