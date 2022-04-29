/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

SeqList createlist()
{
 SeqList sl;
 sl.head = nextfreeloc++;
 sl.size = 0;
 st[sl.head].next = -1;
 return (sl);
}

void printJob (Job j)
{
printf ("JOB ID = %d, Priority = %d, Arr time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}


int inputJobs (JobList list)
{
 int i; int size;

 printf("\n Enter the Number of Jobs :");
 scanf("%d", &size);

 for (i=0;i<size;i++)
 {
  printf ("\nEnter job ID");
  scanf ("%d",&list[i].id);
  printf ("Enter Priority (from 0 - 2)");
  scanf ("%d",&list[i].pri);
  printf ("Execution Time");
  scanf ("%d",&list[i].et);
  printf ("Arrival Time");
  scanf ("%d",&list[i].at);
 }
 return size;
}

SeqList insert(Job j , SeqList sl)
{
int i,temp;
 for (i=sl.head ; st[i].next != -1 ; i=st[i].next)
 {
  if (compare(st[st[i].next].ele , j) == GREATER)
   break;
 }
 temp = nextfreeloc++;
 st[temp].next = st[i].next;
 st[temp].ele = j;
 st[i].next = temp;
 sl.size++;
 return sl;
}
  
void insertelements (JobList list , int size, SeqList s[3])
{
for(int i = 2; i >=0; i--)
{
 for(int j = 0; j < size; j++)
 {
  if(list[j].pri == i)
  {
   s[i] = insert(list[j] , s[i]);
  }
 }
}
}

void copy_sorted_ele(SeqList s[3] , JobList ele)
{
int i,j;
 int index = 0;
 printf ("\n \n");
 for (i=2 ; i>=0 ; i--)
 {
  for (j=st[s[i].head].next ; st[j].next != -1; j = st[j].next)
  {
   ele[index] = st[j].ele;
   index++;
  }  
  ele[index] = st[j].ele; 
  index++;
 }
}

void printlist(SeqList sl)
{
int i;
  for (i=st[sl.head].next; st[i].next != -1; i=st[i].next)
  {
    printJob (st[i].ele);
  }
  printJob(st[i].ele);
}

void printJobList(JobList list, int size)
{
int i;
 for (i=0;i<size;i++)
 {
  printJob (list[i]);
 }
}

void sortJobList(JobList list, int size)
{
 SeqList seq[3];
 seq[0] = createlist();
 seq[1] = createlist();
 seq[2] = createlist();
 insertelements (list, size, seq);
 printlist(seq[0]);   
 printlist(seq[1]);
 printlist(seq[2]);
 copy_sorted_ele (seq , list); 
}
