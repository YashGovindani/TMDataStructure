#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
void mergeSort(void *x,int lowerBound,int upperBound,int es,int (*p2f)(void *,void *))
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
merge(x,lb1,ub1,lb2,ub2,es,p2f);
}
free(lbStack1);
free(ubStack1);
free(lbStack2);
free(ubStack2);
}
int comparator(void *left,void *right)
{
return (*((int *)left))-(*((int *)right));
}
int main()
{
int *x;
int m,req,y;
printf("Enter your requirement : ");
scanf("%d",&req);
fflush(stdin);
fpurge(stdin); // for mac OS
if(req<=0)
{
printf("Invalid requirement : %d\n",req);
return 0;
}
m=req-1;
x=(int *)malloc(sizeof(int)*req);
if(!x)
{
printf("unable to allocate memory for %d elements\n",req);
return 0;
}
for(y=0;y<=m;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
fpurge(stdin); // for mac OS
}
mergeSort(x,0,m,sizeof(int),comparator);
for(y=0;y<=m;y++) printf("%d\n",x[y]);
free(x);
return 0;
}
