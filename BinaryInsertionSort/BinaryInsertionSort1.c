#include<stdio.h>
int main()
{
int x[10],y,size,m,lb,ub,si,ei,mid,e,f,g,num;
size=10;
m=size-1;
// input
for(y=0;y<=m;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fpurge(stdin);
}
lb=0;
ub=m;
// logic to sort
for(y=lb+1;y<=ub;y++)
{
si=lb;
ei=y-1;
num=x[y];
while(si<=ei)
{
mid=(si+ei)/2;
if(x[mid]==num)
{
si=mid;
break;
}
else if(num<x[mid]) ei=mid-1;
else si=mid+1;
}
for(e=y-1,f=y;e>=si;e--,f--) x[f]=x[e];
x[si]=num;
}
// output
for(y=0;y<=m;y++) printf("%d\n",x[y]);
return 0;
}
