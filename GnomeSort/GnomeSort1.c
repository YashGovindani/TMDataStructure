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
e=lb+1;
f=lb;
while(1)
{
while(e>lb && x[f]>x[e])
{
g=x[f];
x[f]=x[e];
x[e]=g;
f--;
e--;
}
if(e==0)
{
e++;
f++;
}
while(e<=ub && x[f]<=x[e])
{
e++;
f++;
}
if(e>ub) break;
}
// output
for(y=0;y<=m;y++) printf("%d\n",x[y]);
return 0;
}
