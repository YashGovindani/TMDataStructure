#include<stdio.h>

int main()
{
int x[10],m,size,y,e,f,g,ri,lb,ub;
size=10;
m=size-1;
lb=0;
ub=m;
// input
for(y=0;y<=m;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fpurge(stdin);
}
// logic to sort
for(y=ub;y>lb;y--)
{
// logic to find index of largest number
for(ri=lb,e=lb+1;e<=y;e++)
{
if(x[e]>x[ri]) ri=e;
}
// logic to reverse array
for(e=lb,f=ri;e<f;e++,f--)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
for(e=lb,f=y;e<f;e++,f--)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
}
// output
for(y=0;y<=m;y++) printf("%d\n",x[y]);
return 0;
}
