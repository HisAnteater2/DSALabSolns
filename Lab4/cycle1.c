#include "cycle.h"

int testCyclic(struct linkedList * Ls){
    if(Ls -> count < 3){
        return 0;
    }
    struct node * hare = Ls -> first;
    struct node * tort = Ls -> first;
    do{
        if((hare -> next==NULL) || ((hare -> next) -> next == NULL))
        return 0;
        hare = (hare -> next) -> next;
        tort = tort -> next;
    }while(hare>tort);
    return 1;
}