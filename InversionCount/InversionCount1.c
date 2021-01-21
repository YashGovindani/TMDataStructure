#include<stdio.h>

int main()
{
int x[10],size,lb,ub,iep,oep,e,f,m,inversionCount;
size=10;
m=size-1;
// input
for(e=0;e<=m;e++)
{
printf("Enter a number : ");
scanf("%d",&x[e]);
fpurge(stdin);
}
lb=0;
ub=m;
// logic calculate inversion count
oep=ub-1;
iep=ub;
inversionCount=0;
for(e=lb;e<=oep;e++)
{
for(f=e+1;f<=iep;f++) if(x[e]>x[f]) inversionCount++;
}
// output
printf("%d\n",inversionCount);
return 0;
}
