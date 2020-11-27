#include<stdio.h>

int main()
{
int x[5];
int y,e,f,g,oep,iep;
for(y=0;y<5;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
}

oep=5-2;
iep=5-1;
e=0;
while(e<=oep)
{
f=e+1;
while(f<=iep)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
f++;
}
e++;
}

for(y=0;y<5;y++)
{
printf("%d\n",x[y]);
}
return 0;
}
