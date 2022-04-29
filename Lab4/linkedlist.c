#include "linkedlist.h"
#include "cycle.h"
#include <sys/time.h>
struct linkedList * createList(int N){
    srand(time(0));
    struct linkedList * Ls = (struct linkedList *) myalloc (sizeof(struct linkedList));
    struct node * link; struct node * temp;
    link = (struct node*) myalloc (sizeof(struct node));
    link -> element = rand();
    Ls -> count = 1;
    Ls -> first = link;
    for(int i=1; i<N; i++){
        temp = link;
        link = (struct node*) myalloc (sizeof(struct node));
        temp -> next = link;
        link -> element = rand();
        Ls -> count++;
    }
    Ls -> last = link;
    return Ls;
}
struct linkedList * createCycle(struct linkedList * Ls){
    int choice = rand()%2;
    if (choice==1){
        struct node * link = Ls -> first;
        int r = rand() % Ls->count;
        for(int i=1; i<=r; i++){
            link = link -> next;
        }
        (Ls -> last) -> next = link;
    }
    return Ls;
}
int main(int argc, char *argv[]){
    struct timeval t1, t2;
    double elapsedTime;
    // start timer
 gettimeofday(&t1, NULL);
    srand(time(0));
    int N = atoi(argv[1]);
    struct linkedList * Ls = createList(N);
    Ls = createCycle(Ls);

    if(testCyclic(Ls)==1){
        printf("Cyclic\n");
    }
    else{
        printf("Linear\n");
    }
    gettimeofday(&t2, NULL);
    // compute and print the elapsed time in millisec
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
    printf("Total time is %lf ms.\n", elapsedTime);
    printf("Number of variables= %d.\n", N);
    printf("Total heap space used = %lld.\n", heapsize());
}