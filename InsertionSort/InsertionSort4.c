#include<stdio.h>
#include<stdlib.h>

void insertionSort(int *data,int size)
{
int y,z,num,m;
m=size-1;
for(y=1;y<=m;y++)
{
for(num=data[y],z=y-1;z>=0 && data[z]>num;z--) data[z+1]=data[z];
data[z+1]=num;
}
}

int main()
{
int *x;
int y,m,req;
printf("Enter requirement : ");
scanf("%d",&req);
fflush(stdin);
if(req<=0)
{
printf("Invalid requirement : %d\n",req);
return 0;
}
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Unable to allocate memory for requirement : %d\n",req);
return 0;
}
m=req-1;
for(y=0;y<=m;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
}
insertionSort(x,req);
for(y=0;y<=m;y++) printf("%d\n",x[y]);
return 0;
}
