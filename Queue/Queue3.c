#include<stdlib.h>
#include<string.h>
#include<stdio.h>
typedef struct _queue_node
{
void *data;
struct _queue_node *next;
}QueueNode;
typedef struct _queue
{
QueueNode *start;
QueueNode *end;
int size;
int elementSize;
}Queue;
void initQueue(Queue *queue,int elementSize)
{
queue->start=NULL;
queue->end=NULL;
queue->size=0;
queue->elementSize=elementSize;
}
int isQueueEmpty(Queue *queue)
{
return queue->size==0;
}
void addToQueue(Queue *queue,void *data)
{
QueueNode *t;
t=(QueueNode *)malloc(sizeof(QueueNode));
t->data=(void *)malloc(queue->elementSize);
memcpy(t->data,data,queue->elementSize);
t->next=NULL;
if(queue->start==NULL)
{
queue->start=t;
queue->end=t;
}
else
{
queue->end->next=t;
queue->end=t;
}
queue->size++;
}
void removeFromQueue(Queue *queue,void *data)
{
QueueNode *t;
memcpy(data,queue->start->data,queue->elementSize);
t=queue->start;
queue->start=t->next;
if(queue->start==NULL) queue->end=NULL;
free(t);
queue->size--;
}
void clearQueue(Queue *queue)
{
QueueNode *t;
while(queue->start!=NULL)
{
t=queue->start;
queue->start=t->next;
free(t->data);
free(t);
}
queue->size=0;
queue->end=NULL;
}
int main()
{
int ch,num;
Queue queue;
initQueue(&queue,sizeof(int));
while(1)
{
printf("1. Add to queue\n");
printf("2. Remove from queue\n");
printf("3. exit\n");
printf("Enter your choice : ");
scanf("%d",&ch);
fflush(stdin);
fpurge(stdin); // for mac OS
if(ch==1)
{
printf("Enter a number : ");
scanf("%d",&num);
fflush(stdin);
fpurge(stdin); // for mac OS
addToQueue(&queue,&num);
}
if(ch==2)
{
if(isQueueEmpty(&queue)) printf("Queue is empty\n");
else
{
removeFromQueue(&queue,&num);
printf("%d removed from queue\n",num);
}
}
if(ch==3) break;
}
clearQueue(&queue);
return 0;
}
