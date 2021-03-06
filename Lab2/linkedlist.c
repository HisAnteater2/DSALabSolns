/* linkedlist.c */
#include <stdlib.h>
#include "linkedlist.h"
void insertFirst(struct linkedList * head, int ele){
 //create a node
 struct node *link = (struct node*) malloc (sizeof(struct node)); /* by this
you are creating a node whose address is being stored in the link pointer. */
 link->element = ele;

 //point it to old first node
 link->next = head->first;

 //point first to new first node
 head -> first = link;
 head -> count ++;
}
//delete first item
struct node* deleteFirst(struct linkedList * head){
// exercise to implement this operation.
struct node *temp = (head -> first) -> next;
free(head -> first);
head -> first = temp;
head -> count --;
}
//display the list
void printList(struct linkedList * head){
 struct node *ptr = head->first;
 printf("\n[ ");
 //start from the beginning
 while(ptr != NULL){
 printf("%d, ", ptr->element);
 ptr = ptr->next;
 }
 printf("]\n");
}