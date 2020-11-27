#include<stdio.h>
#include<stdlib.h>

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
int *x;
int y,requirement;
printf("Enter requirement : ");
scanf("%d",&requirement);
fflush(stdin);
if(requirement<=0)
{
printf("Invalid requirement\n");
return 0;
}
x=(int *)malloc(sizeof(int)*requirement);
if(x==NULL)
{
printf("Cannot allocate memeory for %d numbers\n",requirement);
return 0;
}
for(y=0;y<requirement;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
}
linearSort(x,requirement);
for(y=0;y<requirement;y++)
{
printf("%d\n",x[y]);
}
return 0;
}
