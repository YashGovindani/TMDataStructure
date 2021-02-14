#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct __$__linked_list_node
{
void *ptr;
struct __$__linked_list_node *next;
}LinkedListNode;

typedef struct __$__linked_list
{
LinkedListNode *start;
LinkedListNode *end;
int elementSize;
}LinkedList;

void initLinkedList(LinkedList *list,int elementSize)
{
list->start=NULL;
list->end=NULL;
list->elementSize=elementSize;
}

void clear(LinkedList *list)
{
LinkedListNode *node;
while(list->start)
{
node=list->start;
list->start=node->next;
free(node->ptr);
free(node);
}
}

void append(LinkedList *list,void *ptr)
{
LinkedListNode *node;
node=(LinkedListNode *)malloc(sizeof(LinkedListNode));
node->ptr=(void *)malloc(list->elementSize);
memcpy(node->ptr,ptr,list->elementSize);
node->next=NULL;
if(!list->start) list->start=list->end=node;
else
{
list->end->next=node;
list->end=node;
}
}

typedef struct __$__LinkedListIterator
{
LinkedListNode *node;
}LinkedListIterator;

LinkedListIterator * getLinkedListIterator(LinkedList *list)
{
LinkedListIterator *iterator;
iterator=(LinkedListIterator *)malloc(sizeof(LinkedListIterator));
iterator->node=list->start;
return iterator;
}

int hasNext(LinkedListIterator *iterator)
{
if(iterator->node) return 1;
return 0;
}

void * getNext(LinkedListIterator *iterator)
{
LinkedListNode *node;
if(!iterator->node) return NULL;
node=iterator->node;
iterator->node=node->next;
return node->ptr;
}

void printAscendingOrderSequence(int *x,int size)
{
LinkedList *sequences;
LinkedList *sequence;
LinkedListIterator *iterator,*subIterator;
int smallest,i,appended;
if(size<=0) return;
sequences=(LinkedList *)malloc(sizeof(LinkedList));
initLinkedList(sequences,sizeof(LinkedList));
sequence=(LinkedList *)malloc(sizeof(LinkedList));
initLinkedList(sequence,sizeof(int));
append(sequence,x);
append(sequences,sequence);
smallest=x[0];
for(i=1;i<size;i++)
{
appended=0;
if(x[i]<smallest)
{
smallest=x[i];
sequence=(LinkedList *)malloc(sizeof(LinkedList));
initLinkedList(sequence,sizeof(int));
append(sequence,x+i);
append(sequences,sequence);
}
else
{
iterator=getLinkedListIterator(sequences);
while(hasNext(iterator))
{
sequence=(LinkedList *)getNext(iterator);
if(*((int *)sequence->end->ptr)<=x[i])
{
append(sequence,x+i);
appended=1;
}
}
free(iterator);
if(!appended)
{
sequence=(LinkedList *)malloc(sizeof(LinkedList));
initLinkedList(sequence,sizeof(int));
append(sequence,x+i);
append(sequences,sequence);
}
}
}
iterator=getLinkedListIterator(sequences);
while(hasNext(iterator))
{
sequence=(LinkedList *)getNext(iterator);
if(sequence->start!=sequence->end)
{
subIterator=getLinkedListIterator(sequence);
while(hasNext(subIterator)) printf("%d ",*((int *)getNext(subIterator)));
printf("\n");
free(subIterator);
}
clear(sequence);
}
free(iterator);
clear(sequences);
free(sequences);
}

int main()
{
//int x[]={9,7,1,32,19,21,11,121,42,7};
int x[]={12,3,92,-3,76,54,12,93,78};
printAscendingOrderSequence(x,9);
return 0;
}
