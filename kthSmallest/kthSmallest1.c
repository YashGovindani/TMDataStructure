#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void quickSort(void *x,int lowerBound,int upperBound,int es,int (*p2f)(void *,void *))
{
int stack[1024][2],top,pp,lb,ub,y,e,f,size;
void *g=malloc(es);
size=upperBound-lowerBound+1;
top=size;
top--;
stack[top][0]=lowerBound;
stack[top][1]=upperBound;
while(top!=size)
{
lb=stack[top][0];
ub=stack[top][1];
top++;
e=lb;
f=ub;
while(e<f)
{
while(p2f(x+(e*es),x+(es*lb))<=0) e++;
while(p2f(x+(f*es),x+(lb*es))>0) f--;
if(e<f)
{
memcpy(g,x+(e*es),es);
memcpy(x+(e*es),x+(f*es),es);
memcpy(x+(f*es),g,es);
}
else
{
memcpy(g,x+(f*es),es);
memcpy(x+(f*es),x+(lb*es),es);
memcpy(x+(lb*es),g,es);
pp=f;
}
}
if(pp+1<ub)
{
top--;
stack[top][0]=pp+1;
stack[top][1]=ub;
}
if(lb<pp-1)
{
top--;
stack[top][0]=lb;
stack[top][1]=pp-1;
}
}
free(g);
}

int comparator(void *left,void *right)
{
int *a,*b;
a=(int *)left;
b=(int *)right;
return (*a)-(*b);
}

typedef struct __$__linked_list_node
{
int num;
struct __$__linked_list_node *previous;
struct __$__linked_list_node *next;
}LinkedListNode;

typedef struct __$__linked_list
{
LinkedListNode *start;
LinkedListNode *end;
}LinkedList;

void initLinkedList(LinkedList *list)
{
list->start=NULL;
list->end=NULL;
}

void clear(LinkedList *list)
{
LinkedListNode *node;
while(list->start)
{
node=list->start;
list->start=node->next;
free(node);
}
}

int addFirstKElements(LinkedList *list,int *x,int low,int high,int k)
{
int i,j;
int *tmp;
LinkedListNode *node;
tmp=(int *)malloc(sizeof(int)*k);
for(i=0,j=low;i<k;i++,j++) tmp[i]=x[j];
quickSort(tmp,0,k-1,sizeof(int),comparator);
node=(LinkedListNode *)malloc(sizeof(LinkedListNode));
node->previous=NULL;
node->next=NULL;
node->num=tmp[0];
list->start=node;
list->end=node;
for(i=1;i<k;i++)
{
node=(LinkedListNode *)malloc(sizeof(LinkedListNode));
node->previous=list->end;
node->num=tmp[i];
node->next=NULL;
list->end->next=node;
list->end=node;
}
free(tmp);
return j;
}

int kthSmallest(int *x,int low,int high,int k)
{
int toBeReturned,i;
LinkedList *list;
LinkedListNode *node,*newNode;
list=(LinkedList *)malloc(sizeof(LinkedList));
initLinkedList(list);
for(i=addFirstKElements(list,x,low,high,k);i<=high;i++)
{
node=list->start;
while(node)
{
if(x[i]>node->num) node=node->next;
else if(node==list->end)
{
node->num=x[i];
break;
}
else
{
newNode=(LinkedListNode *)malloc(sizeof(LinkedListNode));
newNode->previous=node->previous;
newNode->num=x[i];
newNode->next=node;
if(list->start!=node) node->previous->next=newNode;
node->previous=newNode;
node=list->end;
list->end=node->previous;
list->end->next=NULL;
free(node);
break;
}
}
}
toBeReturned=list->end->num;
clear(list);
free(list);
return toBeReturned;
}
int main()
{
int x[]={6,4,12,3,32,76,54,19,27,62};
printf("%d\n",kthSmallest(x,0,9,6));
return 0;
}
