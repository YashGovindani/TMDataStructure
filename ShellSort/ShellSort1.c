#include<stdio.h>

int main()
{
int x[10];
int y,e,f,num,m,size,ub,lb,diff;
m=10-1;
lb=0;
ub=m;
for(y=0;y<=m;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
}
size=ub-lb+1;
diff=size/2;
while(diff>=1)
{
e=lb+diff;
while(e<=ub)
{
num=x[e];
f=e-diff;
while(f>=lb && x[f]>num)
{
x[f+diff]=x[f];
f-=diff;
}
x[f+diff]=num;
e+=diff;
}
diff/=2;
}
for(y=0;y<=m;y++) printf("%d\n",x[y]);
return 0;
}
