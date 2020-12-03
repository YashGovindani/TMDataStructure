#include<stdio.h>

void insertionSort(int *data,int size)
{
int e,f,num,m;
m=size-1;
for(e=1;e<=m;e++)
{
for(num=data[e],f=e-1;f>=0 && data[f]>num;f--) data[f+1]=data[f];
data[f+1]=num;
}
}

int main()
{
int x[5];
int y,m;
m=5-1;
for(y=0;y<=m;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
}
insertionSort(x,5);
for(y=0;y<=m;y++) printf("%d\n",x[y]);
return 0;
}
