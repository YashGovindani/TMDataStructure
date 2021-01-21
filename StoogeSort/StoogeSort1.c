#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct __stack_node
{
void *data;
struct __stack_node *next;
}StackNode;

typedef struct __stack
{
int elementSize;
StackNode *top;
int size;
}Stack;

void initStack(Stack *stack,int elementSize)
{
stack->elementSize=elementSize;
stack->top=NULL;
stack->size=0;
}

int isEmpty(Stack *stack)
{
return stack->size==0;
}

void push(Stack *stack,const void *data)
{
StackNode *t;
t=(StackNode *)malloc(sizeof(StackNode));
t->data=(void *)malloc(stack->elementSize);
memcpy(t->data,data,stack->elementSize);
t->next=stack->top;
stack->top=t;
stack->size++;
}

void pop(Stack *stack,void *data)
{
StackNode *t;
t=stack->top;
stack->top=stack->top->next;
stack->size--;
memcpy(data,t->data,stack->elementSize);
free(t->data);
free(t);
}

int main()
{
int x[10],y,size,m,lowerBound,upperBound,lb,ub,e,f,g,partSize;
Stack lbStack,ubStack;
size=10;
m=size-1;
// input
for(y=0;y<=m;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fpurge(stdin);
}
lowerBound=0;
upperBound=m;
// logic to sort
initStack(&lbStack,sizeof(int));
initStack(&ubStack,sizeof(int));
push(&lbStack,&lowerBound);
push(&ubStack,&upperBound);
while(!isEmpty(&lbStack))
{
pop(&lbStack,&lb);
pop(&ubStack,&ub);
size=ub-lb+1;
partSize=size-(size/3);
f=ub-partSize+1;
e=lb+partSize-1;
if(x[lb]>x[ub])
{
g=x[lb];
x[lb]=x[ub];
x[ub]=g;
}
if(size<=3)
{
// left
if(x[lb]>x[e])
{
g=x[lb];
x[lb]=x[e];
x[e]=g;
}
// right
if(x[f]>x[ub])
{
g=x[f];
x[f]=x[ub];
x[ub]=g;
}
// left
if(x[lb]>x[e])
{
g=x[lb];
x[lb]=x[e];
x[e]=g;
}
continue;
}
push(&lbStack,&lb);
push(&ubStack,&e);
push(&lbStack,&f);
push(&ubStack,&ub);
push(&lbStack,&lb);
push(&ubStack,&e);
}
// output
for(y=0;y<=m;y++) printf("%d\n",x[y]);
return 0;
}
