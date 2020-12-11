#include<stdio.h>
int main()
{
int x[10],tmp[10],lbStack1[10],ubStack1[10],lbStack2[10],ubStack2[10];
int top1,top2,a,b,mid,i1,i2,i3,lb1,lb2,lb3,ub1,ub2,ub3,y,req,m;
req=10;
m=req-1;
for(y=0;y<=m;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
fpurge(stdin); // for mac OS
}
top1=req;
top2=req;
top1--;
lbStack1[top1]=0;
ubStack1[top1]=m;
while(top1!=req) // stack1 is not empty
{
// pop from stack1 in a,b
a=lbStack1[top1];
b=ubStack1[top1];
top1++;
// push a,b on stack2
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
while(top2!=req) // stack2 is not empty
{
// pop from stack2 in lb1,ub2
lb1=lbStack2[top2];
ub2=ubStack2[top2];
top2++;
ub1=(lb1+ub2)/2;
lb2=ub1+1;
// logic to merge  starts here
lb3=lb1;
ub3=ub2;
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
// copy back
i3=lb3;
while(i3<=ub3)
{
x[i3]=tmp[i3];
i3++;
}
}
for(y=0;y<=m;y++) printf("%d\n",x[y]);
return 0;
}
