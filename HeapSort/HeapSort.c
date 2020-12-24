#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void toMaxHeap(void *x,int lb,int ub,int es,int (*p2f)(void *,void *))
{
int y,ci,ri;
void *g;
x+=(es*lb);
ub-=lb;
lb=0;
g=(void *)malloc(es);
y=lb+1;
while(y<=ub)
{
ci=y;
while(ci>lb)
{
ri=(ci-1)/2;
if(p2f(x+(es*ci),x+(es*ri))>0)
{
memcpy(g,x+(es*ci),es);
memcpy(x+(es*ci),x+(es*ri),es);
memcpy(x+(es*ri),g,es);
ci=ri;
}else break;
}
y++;
}
free(g);
}
void adjustHeap(void *x,int lb,int ub,int es,int (*p2f)(void *,void *))
{
int ri,y,rci,lci,swi;
void *g;
x+=(es*lb);
ub-=lb;
lb=0;
g=(void *)malloc(es);
y=ub;
ri=lb;
while(ri<y)
{
lci=(ri*2)+1;
if(lci>y) break;
rci=lci+1;
if(rci>y) swi=lci;
else
{
if(p2f(x+(es*lci),x+(es*rci))>0) swi=lci;
else swi=rci;
}
if(p2f(x+(es*swi),x+(es*ri))>0)
{
memcpy(g,x+(es*swi),es);
memcpy(x+(es*swi),x+(es*ri),es);
memcpy(x+(es*ri),g,es);
ri=swi;
}else break;
}
free(g);
}
void heapSort(void *x,int lb,int ub,int es,int (*p2f)(void *,void *))
{
int y,ci,ri,lci,rci,swi;
void *g;
x+=(es*lb);
ub-=lb;
lb=0;
g=(void *)malloc(es);
toMaxHeap(x,lb,ub,es,p2f);
y=ub;
while(y>lb)
{
memcpy(g,x+(es*lb),es);
memcpy(x+(es*lb),x+(es*y),es);
memcpy(x+(es*y),g,es);
y--;
adjustHeap(x,lb,y,es,p2f);
}
free(g);
}
int comparator(void *left,void *right)
{
return (*((int *)left))-(*((int *)right));
}
int main()
{
int x[6],y,ci,ri,lci,rci,swi,g;
y=0;
while(y<=5)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
fpurge(stdin); // for mac OS
y++;
}
heapSort(x,1,5,sizeof(int),comparator);
for(y=0;y<=5;y++) printf("%d\n",x[y]);
}
