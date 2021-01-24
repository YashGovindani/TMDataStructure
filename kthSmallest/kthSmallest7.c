// Logic using selection sort
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
int x[]={62,5,91,54,32,79,37,63,51,49};
int e,f,g,j,k,lb,ub,size,m,smallest;
size=10;
m=size-1;
lb=0;
ub=m;
k=4;
for(e=0;e<k;e++)
{
j=lb+e;
smallest=j;
for(f=smallest+1;f<=ub;f++) if(x[f]<x[smallest]) smallest=f;
g=x[smallest];
x[smallest]=x[j];
x[j]=g;
}
printf("%d\n",x[k-1]);
return 0;
}
