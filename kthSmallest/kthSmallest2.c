// Sir's logic creating partition
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
int x[]={62,5,91,54,32,79,37,63,51,49};
int e,f,g,k,lb,ub;
k=4;
k--;
lb=0;
ub=9;
while(1)
{
// upper loop
for(e=lb;e<k;e++)
{
if(x[e]>x[k])
{
g=x[e];
x[e]=x[k];
x[k]=g;
break;
}
}
// lower loop
for(f=ub;f>k;f--)
{
if(x[f]<x[k])
{
g=x[f];
x[f]=x[k];
x[k]=g;
break;
}
}
if(e==k && f==k) break;
}
printf("%d\n",x[k]);
return 0;
}
