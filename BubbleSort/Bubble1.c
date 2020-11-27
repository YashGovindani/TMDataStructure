// In this example whole code is written in main function.
#include<stdio.h>
int main()
{
int x[5];
int e,f,g,y,m;
for(y=0;y<=4;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
}
m=3; // 5-2
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
for(y=0;y<=4;y++)
{
printf("%d\n",x[y]);
}
return 0;
}
