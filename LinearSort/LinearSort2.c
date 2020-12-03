#include<stdio.h>

void linearSort(int *x,int size)
{
int e,f,g,oep,iep;
oep=size-2;
iep=size-1;
e=0;
while(e<=oep)
{
f=e+1;
while(f<=iep)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
f++;
}
e++;
}
}

int main()
{
int m;
m=5;
int x[m];
int y;
for(y=0;y<m;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
}
linearSort(x,m);
for(y=0;y<m;y++)
{
printf("%d\n",x[y]);
}
return 0;
}
