// In this example we will implement seperate function for bubble sort
#include<stdio.h>

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
int x[5];
int y;
for(y=0;y<=4;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
}
bubbleSort(x,5);
for(y=0;y<=4;y++)
{
printf("%d\n",x[y]);
}
return 0;
}
