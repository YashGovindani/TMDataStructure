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

int main()
{
int *x,req,m,y;
printf("Enter your requirement : ");
scanf("%d",&req);
fflush(stdin);
x=(int *)malloc(sizeof(int)*req);
m=req-1;
y=0;
while(y<=m)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
y++;
}
quickSort(x,0,m,sizeof(int),comparator);
for(y=0;y<=m;y++) printf("%d\n",x[y]);
return 0;
}
