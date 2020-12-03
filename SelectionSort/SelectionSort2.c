#include<stdio.h>

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
int x[5],y,req;
req=5;
y=0;
while(y<req)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
y++;
}
selectionSort(x,req);
for(y=0;y<req;y++) printf("%d\n",x[y]);
return 0;
}
