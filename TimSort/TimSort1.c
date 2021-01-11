#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void merge(void *x,int lb1,int ub1,int lb2,int ub2,int es,int (*p2f)(void *,void *))
{
int size1,size2,size3,i1,i2,i3,lb3,ub3;
size1=ub1-lb1+1;
size2=ub2-lb2+1;
size3=size1+size2;
void *tmp;
tmp=(void *)malloc(sizeof(es)*size3);
lb3=0;
ub3=size3-1;
i1=lb1;
i2=lb2;
i3=lb3;
while(i1<=ub1 && i2<=ub2)
{
if(p2f(x+(i1*es),x+(i2*es))<0)
{
memcpy(tmp+(i3*es),x+(i1*es),es);
i1++;
}
else
{
memcpy(tmp+(i3*es),x+(i2*es),es);
i2++;
}
i3++;
}
while(i1<=ub1)
{
memcpy(tmp+(i3*es),x+(i1*es),es);
i3++;
i1++;
}
while(i2<=ub2)
{
memcpy(tmp+(i3*es),x+(i2*es),es);
i3++;
i2++;
}
//copy back
for(i1=lb1,i3=lb3;i1<=ub1;i1++,i3++) memcpy(x+(i1*es),tmp+(i3*es),es);
for(i2=lb2;i2<=ub2;i2++,i3++) memcpy(x+(i2*es),tmp+(i3*es),es);
}

void quickSort(void *x,int lowerBound,int upperBound,int es,int (*p2f)(void *,void *))
{
int stack[10000][2],top,pp,lb,ub,y,e,f,size;
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
int x[5000],size,m,y,lb,ub,segmentSize,e,f,mid;
size=5000;
m=size-1;
y=0;
srand(time(0));
// input
for(y=0;y<=m;y++) x[y]=rand();
lb=0;
ub=m;
// logic to sort
segmentSize=256;
// sort segments
for(e=lb,f=lb+segmentSize-1;f<=ub;e+=segmentSize,f+=segmentSize) quickSort(x,e,f,sizeof(int),comparator);
if(e<ub && f>ub) quickSort(x,e,ub,sizeof(int),comparator);
// merge segments
for(y=2*segmentSize;y<=size;y*=2)
{
for(e=lb,f=lb+y-1;f<=ub;e+=y,f+=y)
{
mid=e+(y/2)-1;
merge(x,e,mid,mid+1,f,sizeof(int),comparator);
}
if(e<ub && f>ub && ub-e+1>y/2)
{
mid=e+(y/2)-1;
merge(x,e,mid,mid+1,ub,sizeof(int),comparator);
}
}
y/=2;
if(y<ub)
{
merge(x,lb,y-1,y,ub,sizeof(int),comparator);
}
// output
for(y=0;y<=m;y++) printf("%d\n",x[y]);
return 0;
}
