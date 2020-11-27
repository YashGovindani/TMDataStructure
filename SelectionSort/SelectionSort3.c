#include<stdio.h>
#include<stdlib.h>

void selectionSort(int *data,int size)
{
int e,f,g,si,oep,iep;
oep=size-2;
iep=size-1;
e=0;
while(e<=oep)
{
f=e+1;
si=e;
while(f<=iep)
{
if(data[f]<data[si]) si=f;
f++;
}
g=data[si];
data[si]=data[e];
data[e]=g;
e++;
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
printf("Invalid requirement : %d",req);
return 0;
}
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Cannot allocate memory for the requirement : %d\n",req);
return 0;
}
m=req-1;
y=0;
while(y<=m)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
y++;
}
selectionSort(x,req);
for(y=0;y<=m;y++) printf("%d\n",x[y]);
return 0;
}
