// Sir's logic using min heap
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

int comparator(void *left,void *right)
{
return (*((int *)right))-(*((int *)left));
}

int main()
{
int x[]={62,5,91,54,32,79,37,63,51,49};
int g,i,k,lb,ub,m,size;
k=4;
size=10;
m=size-1;
lb=0;
ub=m;
toMaxHeap(x,lb,ub,sizeof(int),comparator);
for(i=0;i<k;i++)
{
g=x[lb];
x[lb]=x[ub];
x[ub]=g;
ub--;
adjustHeap(x,lb,ub,sizeof(int),comparator);
}
printf("%d\n",x[m-k+1]);
return 0;
}
