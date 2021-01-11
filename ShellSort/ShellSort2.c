#include<stdio.h>
void shellSort(int *x,int lb,int ub)
{
int size,diff,e,f,num;
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
}

int main()
{
int x[10],y,m;
m=10-1;
for(y=0;y<=m;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
}
shellSort(x,1,m);
for(y=0;y<=m;y++) printf("%d\n",x[y]);
return 0;
}
