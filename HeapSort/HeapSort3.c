#include<stdio.h>
void toMaxHeap(int *x,int lb,int ub)
{
int y,ci,ri,g;
x+=lb;
ub-=lb;
lb=0;
y=lb+1;
while(y<=ub)
{
ci=y;
while(ci>lb)
{
ri=(ci-1)/2;
if(x[ci]>x[ri])
{
g=x[ci];
x[ci]=x[ri];
x[ri]=g;
ci=ri;
}else break;
}
y++;
}
}
void adjustHeap(int *x,int lb,int ub)
{
int ri,y,rci,lci,swi,g;
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
if(x[lci]>x[rci]) swi=lci;
else swi=rci;
}
if(x[swi]>x[ri])
{
g=x[swi];
x[swi]=x[ri];
x[ri]=g;
ri=swi;
}else break;
}
}
void heapSort(int *x,int lb,int ub)
{
int y,ci,ri,lci,rci,swi,g;
toMaxHeap(x,lb,ub);
y=ub;
while(y>lb)
{
g=x[lb];
x[lb]=x[y];
x[y]=g;
y--;
adjustHeap(x,lb,y);
}
}
int main()
{
int x[10],y,ci,ri,lci,rci,swi,g;
y=0;
while(y<=9)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
fpurge(stdin); // for mac OS
y++;
}
heapSort(x,0,9);
for(y=0;y<=9;y++) printf("%d\n",x[y]);
}
