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

int getLargest(int *ptr,int lb,int ub)
{
int i,largest;
largest=ptr[lb];
for(i=lb+1;i<=ub;i++) if(ptr[i]>largest) largest=ptr[i];
return largest;
}

int getDigitCount(int num)
{
int dc;
dc=1;
if(num<0) num*=-1;
while(num>9)
{
dc++;
num/=10;
}
return dc;
}

void spreadForRadixSort(int *ptr,int lb,int ub,int e,int f,Queue *queues)
{
int num,y,i;
y=lb;
while(y<=ub)
{
num=ptr[y];
i=(num%e)/f;
addToQueue(&queues[i],&num);
y++;
}
}

void collectForRadixSort(int *ptr,int lb,Queue *queues)
{
int i,y;
i=lb;
y=0;
while(y<=9)
{
while(!isQueueEmpty(&queues[y]))
{
removeFromQueue(&queues[y],&ptr[i]);
i++;
}
y++;
}
}

void radixSort(int *ptr,int lb,int ub)
{
int largest,size,dc,e,f,i,k,y,num;
Queue queues[10];
for(y=0;y<=9;y++) initQueue(&queues[y],sizeof(int));
for(y=lb-1,i=lb;i<=ub;i++)
{
if(ptr[i]<0)
{
y++;
if(y==i) ptr[y]*=-1;
else
{
num=ptr[y];
ptr[y]=(-1)*ptr[i];
ptr[i]=num;
}
}
}
if(y>lb) radixSort(ptr,lb,y);
for(e=lb,f=y;e<=f;e++,f--)
{
num=(-1)*ptr[e];
ptr[e]=(-1)*ptr[f];
ptr[f]=num;
}
if(y==ub) return;
lb=y+1;
largest=getLargest(ptr,lb,ub);
dc=getDigitCount(largest);
e=10;
f=1;
k=1;
while(k<=dc)
{
spreadForRadixSort(ptr,lb,ub,e,f,queues);
collectForRadixSort(ptr,lb,queues);
e*=10;
f*=10;
k++;
}
}

int main()
{
int x[10],y,m,size;
printf("Enter size : ");
scanf("%d",&size);
fpurge(stdin);
m=size-1;
for(y=0;y<=m;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fpurge(stdin);
}
radixSort(x,1,m);
for(y=0;y<=m;y++) printf("%d\n",x[y]);
return 0;
}
