#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
int lb,ub;
struct Node *next;
};
struct Node *top;
int isEmpty()
{
return top==NULL;
}
void push(int lowerBound,int upperBound)
{
struct Node *t;
t=(struct Node *)malloc(sizeof(struct Node));
t->lb=lowerBound;
t->ub=upperBound;
t->next=top;
top=t;
}
void pop(int *lowerBound,int *upperBound)
{
if(top==NULL) return;
struct Node *t;
t=top;
top=top->next;
*lowerBound=t->lb;
*upperBound=t->ub;
free(t);
}
int findPartitionPoint(void *x,int lb,int ub,int es,int (*p2f)(void *,void *))
{
int e,f,pp;
void *g=(void *)malloc(es);
e=lb;
f=ub;
while(e<f)
{
while(p2f(x+(e*es),x+(lb*es))<=0 && e<ub) e++;
while(p2f(x+(f*es),x+(lb*es))>0) f--;
if(e<f)
{
memcpy(g,x+(e*es),es);
memcpy(x+(e*es),x+(f*es),es);
memcpy(x+(f*es),g,es);
}
else
{
memcpy(g,x+(lb*es),es);
memcpy(x+(lb*es),x+(f*es),es);
memcpy(x+(f*es),g,es);
pp=f;
}
}
return pp;
}
void quickSort(void *x,int lowerBound,int upperBound,int es,int (*p2f)(void *,void *))
{
int lb,ub,pp;
push(lowerBound,upperBound);
while(!isEmpty())
{
pop(&lb,&ub);
pp=findPartitionPoint(x,lb,ub,es,p2f);
if(pp+1<ub) push(pp+1,ub);
if(lb<pp-1) push(lb,pp-1);
}
}
int comparator(void *left,void *right)
{
int *a,*b;
a=(int *)left;
b=(int *)right;
return (*a)-(*b);
}
int main()
{
int *x,req,m,y;
printf("Enter your requirement : ");
scanf("%d",&req);
fflush(stdin);
if(req<=0)
{
printf("Invalid requirement : %d\n",req);
return 0;
}
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Unable allocate memeory for %d numbers\n",req);
return 0;
}
m=req-1;
for(y=0;y<=m;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
}
quickSort(x,0,m,sizeof(int),comparator);
for(y=0;y<=m;y++) printf("%d\n",x[y]);
free(x);
return 0;
}
