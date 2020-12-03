#include<stdio.h>

int main()
{
int x[5];
int y,e,f,num,m;
m=5-1;
for(y=0;y<=m;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
}
e=1;
while(e<=m)
{
num=x[e];
f=e-1;
while(f>=0 && x[f]>num)
{
x[f+1]=x[f];
f--;
}
x[f+1]=num;
e++;
}
for(y=0;y<=m;y++) printf("%d\n",x[y]);
return 0;
}
