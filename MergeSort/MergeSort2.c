#include<stdio.h>
#include<stdlib.h>
void merge(int *x,int lb1,int ub1,int lb2,int ub2)
{
int size1,size2,size3,i1,i2,i3,lb3,ub3;
size1=ub1-lb1+1;
size2=ub2-lb2+1;
size3=size1+size2;
int *tmp;
tmp=(int *)malloc(sizeof(int)*size3);
lb3=0;
ub3=size3;
i1=lb1;
i2=lb2;
i3=lb3;
while(i1<=ub1 && i2<=ub2)
{
if(x[i1]<x[i2])
{
tmp[i3]=x[i1];
i1++;
}
else
{
tmp[i3]=x[i2];
i2++;
}
i3++;
}
while(i1<=ub1)
{
tmp[i3]=x[i1];
i3++;
i1++;
}
while(i2<=ub2)
{
tmp[i3]=x[i2];
i3++;
i2++;
}
//copy back
for(i1=lb1,i3=lb3;i1<=ub1;i1++,i3++) x[i1]=tmp[i3];
for(i2=lb2;i2<=ub2;i2++,i3++) x[i2]=tmp[i3];
}
void mergeSort(int *x,int lowerBound,int upperBound)
{
int size,top1,top2,a,b,mid,lb1,ub1,lb2,ub2;
int *lbStack1,*ubStack1,*lbStack2,*ubStack2;
size=upperBound-lowerBound+1;
lbStack1=(int *)malloc(sizeof(int)*size);
ubStack1=(int *)malloc(sizeof(int)*size);
lbStack2=(int *)malloc(sizeof(int)*size);
ubStack2=(int *)malloc(sizeof(int)*size);
top1=size;
top2=size;
// push lowerBound, upperBound to stack1
top1--;
lbStack1[top1]=lowerBound;
ubStack1[top1]=upperBound;
while(top1!=size) // stack1 is not empty
{
// pop from stack1 in a,b
a=lbStack1[top1];
b=ubStack1[top1];
top1++;
//push a,b on stack2
top2--;
lbStack2[top2]=a;
ubStack2[top2]=b;
// calculate mid
mid=(a+b)/2;
if(a<mid)
{
// push a,mid on stack1
top1--;
lbStack1[top1]=a;
ubStack1[top1]=mid;
}
if(mid+1<b)
{
// push mid+1,b on stack1
top1--;
lbStack1[top1]=mid+1;
ubStack1[top1]=b;
}
}
while(top2!=size) // stack2 is not empty
{
// pop from stack2 in lb1,ub2
lb1=lbStack2[top2];
ub2=ubStack2[top2];
top2++;
ub1=(lb1+ub2)/2;
lb2=ub1+1;
merge(x,lb1,ub1,lb2,ub2);
}
free(lbStack1);
free(ubStack1);
free(lbStack2);
free(ubStack2);
}
int main()
{
int *x;
int m,req,y;
req=10;
m=req-1;
x=(int *)malloc(sizeof(int)*req);
for(y=0;y<=m;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
fpurge(stdin); // for mac OS
}
mergeSort(x,0,m);
for(y=0;y<=m;y++) printf("%d\n",x[y]);
free(x);
return 0;
}
