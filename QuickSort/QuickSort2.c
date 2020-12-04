#include<stdio.h>

void quickSort(int *x,int lowerBound,int upperBound)
{
int stack[1024][2],top,pp,lb,ub,y,e,f,g,size;
size=upperBound-lowerBound+1;
top=size;
top--;
stack[top][0]=lowerBound;
stack[top][1]=upperBound;
while(top!=size)
{
lb=stack[top][0];
ub=stack[top][1];
top++;
e=lb;
f=ub;
while(e<f)
{
while(x[e]<=x[lb]) e++;
while(x[f]>x[lb]) f--;
if(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
else
{
g=x[f];
x[f]=x[lb];
x[lb]=g;
pp=f;
}
}
if(pp+1<ub)
{
top--;
stack[top][0]=pp+1;
stack[top][1]=ub;
}
if(lb<pp-1)
{
top--;
stack[top][0]=lb;
stack[top][1]=pp-1;
}
}
}

int main()
{
int x[10],req,m,y;
req=10;
m=req-1;
y=0;
while(y<=m)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
y++;
}
quickSort(x,0,m);
for(y=0;y<=m;y++) printf("%d\n",x[y]);
return 0;
}
