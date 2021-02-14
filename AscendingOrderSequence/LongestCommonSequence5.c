#include<stdio.h>
int main()
{
int x[9]={12,3,92,-3,76,54,12,93,78};
int flags[9]={0,0,0,0,0,0,0,0,0};
int e,f,prev,noel;
for(e=0;e<=7;e++)
{
if(flags[e]) continue;
noel=0;
prev=e;
for(f=e+1;f<=8;f++)
{
if(x[f]>x[prev])
{
printf("%d ",x[prev]);
noel++;
prev=f;
flags[f]=1;
}
}
if(prev>e)
{
printf("%d\n",x[prev]);
noel++;
printf("The above %d elements are from index %d to %d\n\n",noel,e,prev);
}
}
return 0;
}
