#include<stdio.h>

int main()
{
int x[10],y,size,m,e,f,g,lb,ub;
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
while(lb<ub)
{
e=lb;
f=lb+1;
for(e=lb,f=lb+1;f<=ub;e++,f++)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
}
ub--;
for(e=ub-1,f=ub;e>=lb;e--,f--)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
}
lb++;
}
// output
for(y=0;y<=m;y++) printf("%d\n",x[y]);
return 0;
}
