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

long myPow(int base,int power)
{
// logic only support positve base and positive power
Stack subPower1Stack,subPower2Stack;
long subPower1,subPower2,subValue1,subValue2,value;
if(power==0) return 1;
if(power==1) return base;
initStack(&subPower1Stack,sizeof(int));
initStack(&subPower2Stack,sizeof(int));
subPower1=power/2;
if(power%2) subPower2=subPower1+1;
else subPower2=subPower1;
push(&subPower1Stack,&subPower1);
push(&subPower2Stack,&subPower2);
while(1)
{
if(subPower1==1) break;
if(subPower1%2) subPower2=1;
else subPower2=0;
subPower1/=2;
subPower2+=subPower1;
push(&subPower1Stack,&subPower1);
push(&subPower2Stack,&subPower2);
}
value=base;
while(!isEmpty(&subPower1Stack))
{
pop(&subPower1Stack,&subPower1);
pop(&subPower2Stack,&subPower2);
printf("popped : %ld,%ld\n",subPower1,subPower2);
subValue1=value;
subValue2=value;
if(subPower1!=subPower2) subValue2*=base;
value*=subValue2;
printf("value : %ld\n",value);
}
return value;
}

int main()
{
printf("pow(7,9) = %ld\n",myPow(7,9));
return 0;
}
