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
for(e=1;e<=m;e++)
{
for(num=x[e],f=e-1;f>=0 && x[f]>num;f--) x[f+1]=x[f];
x[f+1]=num;
}
for(y=0;y<=m;y++) printf("%d\n",x[y]);
return 0;
}
