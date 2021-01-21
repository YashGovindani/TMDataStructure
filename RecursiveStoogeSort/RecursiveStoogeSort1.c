#include<stdio.h>

void stoogeSort(int *x,int lb,int ub)
{
int size,e,f,g,partSize;
size=ub-lb+1;
if(x[lb]>x[ub])
{
g=x[lb];
x[lb]=x[ub];
x[ub]=g;
}
partSize=size-size/3;
e=lb+partSize-1;
f=ub-partSize+1;
if(size<=3)
{
// left
if(x[lb]>x[e])
{
g=x[lb];
x[lb]=x[e];
x[e]=g;
}
// right
if(x[f]>x[ub])
{
g=x[f];
x[f]=x[ub];
x[ub]=g;
}
// left
if(x[lb]>x[e])
{
g=x[lb];
x[lb]=x[e];
x[e]=g;
}
return;
}
stoogeSort(x,lb,e);
stoogeSort(x,f,ub);
stoogeSort(x,lb,e);
}

int main()
{
int x[10],y,size,m;
size=10;
m=size-1;
// input
for(y=0;y<=m;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fpurge(stdin);
}
stoogeSort(x,0,m);
// output
for(y=0;y<=m;y++) printf("%d\n",x[y]);
return 0;
}
