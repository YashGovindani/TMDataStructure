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
int x[10],y,e,f,i,num,largest,dc,k;
Queue queues[10];
for(y=0;y<=9;y++) initQueue(&queues[y],sizeof(int));
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fpurge(stdin);
}
// logic to find largest starts
largest=x[0];
for(y=1;y<=9;y++)
{
if(x[y]>largest) largest=x[y];
}
// logic to find largest ends
// logic to find number of digits starts
dc=1;
num=largest;
while(num>9)
{
num/=10;
dc++;
}
// logic to find number of digits ends
// logic to sort starts
e=10;
f=1;
k=1;
while(k<=dc)
{
// spread out in 10 queues according to digit at kth place
y=0;
while(y<=9)
{
num=x[y];
i=(num%e)/f;
// add the num to ith queue
addToQueue(&queues[i],&num);
y++;
}
// collect all numbers from 10 queues and keep it in array
i=0;
y=0;
while(y<=9)
{
while(!isQueueEmpty(&queues[y]))
{
removeFromQueue(&queues[y],&x[i]);
i++;
}
y++;
}
e*=10;
f*=10;
k++;
}
// logic to sort ends
for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}
