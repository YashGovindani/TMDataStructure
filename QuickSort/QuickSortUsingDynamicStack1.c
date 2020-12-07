#include<stdio.h>
#include<stdlib.h>
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
int findPartitionPoint(int *x,int lb,int ub)
{
int e,f,g,pp;
e=lb;
f=ub;
while(e<f)
{
while(x[e]<=x[lb] && e<ub) e++;
while(x[f]>x[lb]) f--;
if(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
else
{
g=x[f];
x[f]=x[lb];
x[lb]=g;
pp=f;
}
}
return pp;
}
void quickSort(int *x,int lowerBound,int upperBound)
{
int lb,ub,pp;
push(lowerBound,upperBound);
while(!isEmpty())
{
pop(&lb,&ub);
pp=findPartitionPoint(x,lb,ub);
if(pp+1<ub) push(pp+1,ub);
if(lb<pp-1) push(lb,pp-1);
}
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
quickSort(x,0,m);
for(y=0;y<=m;y++) printf("%d\n",x[y]);
free(x);
return 0;
}
