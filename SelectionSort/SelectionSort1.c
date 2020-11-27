#include<stdio.h>
int main()
{
int x[10],y,e,f,g,si;
y=0;
while(y<=9)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
y++;
}
e=0;
while(e<=8)
{
f=e+1;
si=e;
while(f<=9)
{
if(x[f]<x[si]) si=f;
f++;
}
g=x[si];
x[si]=x[e];
x[e]=g;
e++;
}
for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}
