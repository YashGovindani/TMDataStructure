// Logic using bubble sort 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
int x[]={62,5,91,54,32,79,37,63,51,49};
int e,f,g,i,k,size,m,lb,ub;
size=10;
m=size-1;
lb=0;
ub=m;
e=ub-1;
f=ub;
k=4;
for(i=0;i<k;i++)
{
for(e=ub-1,f=ub;e>=lb;e--,f--)
{
if(x[e]>x[f])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
}
}
printf("%d\n",x[k-1]);
return 0;
}
