#include<stdio.h>

int main()
{
int x[10],y,size,m,swapped,lb,ub,e,f,g;
size=10;
m=size-1;
// input
for(y=0;y<=m;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
fpurge(stdin); // for mac OS
}
lb=0;
ub=m;
// logic to sort
while(1)
{
swapped=0;
// starting with lb+odd
for(e=lb+1,f=lb+2;f<=ub;e+=2,f+=2)
{
if(x[f]<x[e])
{
swapped=1;
g=x[e];
x[e]=x[f];
x[f]=g;
}
}
// starting with lb+even
for(e=lb,f=lb+1;f<=ub;e+=2,f+=2)
{
if(x[f]<x[e])
{
swapped=1;
g=x[e];
x[e]=x[f];
x[f]=g;
}
}
if(!swapped) break;
}
//output
for(y=0;y<=m;y++) printf("%d\n",x[y]);
return 0;
}
