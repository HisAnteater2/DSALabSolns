#include "exercise2.h"
long long heapspace = 0;

long long heapsize(){
    return heapspace;
}

void * myalloc(int size){
    heapspace+= size;
    return malloc(size);
}
void myfree(void * ptr, int size){
    heapspace-=size;
    free(ptr);
}