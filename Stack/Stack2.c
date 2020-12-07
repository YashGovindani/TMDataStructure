#include<stdio.h>
#include<stdlib.h>

typedef struct __stack_node
{
int data;
struct __stack_node *next;
}StackNode;

typedef struct __stack
{
StackNode *top;
int size;
}Stack;

void push(Stack *stack,int num)
{
StackNode *t;
t=(StackNode *)malloc(sizeof(StackNode));
t->data=num;
t->next=stack->top;
stack->top=t;
stack->size++;
}

int pop(Stack *stack)
{
StackNode *t;
int data;
t=stack->top;
stack->top=t->next;
stack->size--;
data=t->data;
free(t);
return data;
}

int isEmpty(Stack *stack)
{
//return stack->top==NULL;
return stack->size==0;
}

void initStack(Stack *stack)
{
stack->top=NULL;
stack->size=0;
}

int main()
{
Stack a,b;
initStack(&a);
initStack(&b);
for(int i=0;i<=10;i+=2) push(&a,i);
for(int i=1;i<=9;i+=2) push(&b,i);
while(!isEmpty(&a) && !isEmpty(&b))
{
printf("%d\n",pop(&a));
printf("%d\n",pop(&b));
}
while(!isEmpty(&a)) printf("%d\n",pop(&a));
return 0;
}
