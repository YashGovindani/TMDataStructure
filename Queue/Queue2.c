#include<stdlib.h>
#include<stdio.h>
typedef struct _queue_node
{
int num;
struct _queue_node *next;
}QueueNode;
typedef struct _queue
{
QueueNode *start;
QueueNode *end;
int size;
}Queue;
void initQueue(Queue *queue)
{
queue->start=NULL;
queue->end=NULL;
queue->size=0;
}
int isQueueEmpty(Queue *queue)
{
return queue->size==0;
}
void addToQueue(Queue *queue,int num)
{
QueueNode *t;
t=(QueueNode *)malloc(sizeof(QueueNode));
t->num=num;
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
int removeFromQueue(Queue *queue)
{
int num;
QueueNode *t;
num=queue->start->num;
t=queue->start;
queue->start=t->next;
if(queue->start==NULL) queue->end=NULL;
free(t);
queue->size--;
return num;
}
void clearQueue(Queue *queue)
{
QueueNode *t;
while(queue->start!=NULL)
{
t=queue->start;
queue->start=t->next;
free(t);
}
queue->size=0;
queue->end=NULL;
}
int main()
{
int ch,num;
Queue queue;
initQueue(&queue);
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
addToQueue(&queue,num);
}
if(ch==2)
{
if(isQueueEmpty(&queue)) printf("Queue is empty\n");
else printf("%d removed from queue\n",removeFromQueue(&queue));
}
if(ch==3) break;
}
clearQueue(&queue);
return 0;
}
