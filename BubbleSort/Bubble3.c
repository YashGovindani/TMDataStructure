// In this example bubble sort is implemented using dynamic memory allocation
#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int *x,int size)
{
int e,f,g,m;
m=size-2;
if(m<0) return;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
e++;
f++;
}
m--;
}
}

int main()
{
int *x;
int y,requirement;
printf("Enter your requirement : ");
scanf("%d",&requirement);
fflush(stdin);
if(requirement<=0)
{
printf("Invalid requirement : %d\n",requirement);
return 0;
}
x=(int *)malloc(requirement*sizeof(int));
if(x==NULL)
{
printf("Can not allocate memory for requirement : %d\n",requirement);
return 0;
}
for(y=0;y<requirement;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
}
bubbleSort(x,requirement);
for(y=0;y<requirement;y++)
{
printf("%d\n",x[y]);
}
return 0;
}
