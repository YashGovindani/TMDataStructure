#include<stdio.h>
int main()
{
int x[5],y,e,f,g,si,oep,iep,req;
req=5;
oep=req-2;
iep=req-1;
y=0;
while(y<req)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
y++;
}
e=0;
while(e<=oep)
{
f=e+1;
si=e;
while(f<=iep)
{
if(x[f]<x[si]) si=f;
f++;
}
g=x[si];
x[si]=x[e];
x[e]=g;
e++;
}
for(y=0;y<req;y++) printf("%d\n",x[y]);
return 0;
}
