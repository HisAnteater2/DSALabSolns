/* driver.c */
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
int main(int argc, char *argv[])
{
// Create a file pointer and open the file "stackInput.txt".
FILE * fileptr = fopen(argv[1], "r");
// Declare a pointer to a linked list (stack) and allocate memory to it.
struct linkedList * stack = (struct linkedList *) malloc (sizeof(struct
linkedList));
// In a loop read the file and insert elements into the stack.
while (!feof(fileptr))
{
// read the next element and store into the temp variable.
int temp;
fscanf(fileptr, "%d ", &temp);
// insert temp into the stack.
push(stack,temp);
}
// close the file pointer
fclose(fileptr);
// print the stack.
printList(stack);
// pop out each element.
struct node *ptr = stack->first;
 while(ptr != NULL){
     printf("%d", pop(stack));
     printList(stack);
     ptr = stack->first;
 }
}