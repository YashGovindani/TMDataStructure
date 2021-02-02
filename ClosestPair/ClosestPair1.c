#include<stdio.h>
#include<math.h>

int main()
{
int x[]={1,9,13,4,7};
int y[]={11,12,13,2,16};
int i,j,dx,dy,n2,n1;
double shortestDistance,dist;
n1=0;
n2=1;
dx=x[n2]-x[n1];
dy=y[n2]-y[n1];
shortestDistance=sqrt((dx*dx)+(dy*dy));
for(i=0;i<5;i++)
{
for(j=i+1;j<5;j++)
{
dx=x[j]-x[i];
dy=y[j]-y[i];
dist=sqrt((dx*dx)+(dy*dy));
printf("(%d,%d) (%d,%d) -> %f\n",x[i],y[i],x[j],y[j],dist);
if(dist<shortestDistance)
{
shortestDistance=dist;
n1=i;
n2=j;
}
}
}
printf("nearest : (%d,%d) (%d,%d) -> %f\n",x[n1],y[n1],x[n2],y[n2],shortestDistance);
return 0;
}
