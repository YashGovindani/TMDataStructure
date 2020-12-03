#include<stdio.h>

int main()
{
int m;
m=5;
int x[m];
int y,e,f,g,oep,iep;
for(y=0;y<m;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
}

oep=m-2;
iep=m-1;
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

for(y=0;y<m;y++)
{
printf("%d\n",x[y]);
}
return 0;
}
