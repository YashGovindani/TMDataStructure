#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct Node *next;
};
struct Node *top;
// In main (top=NULL;)
int isEmpty()
{
return top==NULL;
}
void push(int num)
{
struct Node *t;
t=(struct Node *)malloc(sizeof(struct Node));
t->data=num;
t->next=top;
top=t;
}
int pop()
{
struct Node *t;
int data;
data=top->data;
t=top;
top=top->next;
free(t);
return data;
}
int main()
{
top=NULL;
for(int i=0;i<=9;i++) push(i);
while(!isEmpty()) printf("%d\n",pop());
return 0;
}
