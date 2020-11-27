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
int x[5];
int y;
for(y=0;y<5;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
}
linearSort(x,5);
for(y=0;y<5;y++)
{
printf("%d\n",x[y]);
}
return 0;
}
