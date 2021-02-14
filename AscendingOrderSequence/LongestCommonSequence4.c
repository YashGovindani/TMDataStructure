#include<stdio.h>
int main()
{
int x[9]={12,3,92,-3,76,54,12,93,78};
int flags[9]={0,0,0,0,0,0,0,0,0};
int e,f,prev;
for(e=0;e<=7;e++)
{
if(flags[e]) continue;
prev=e;
for(f=e+1;f<=8;f++)
{
if(x[f]>x[prev])
{
printf("%d ",x[prev]);
prev=f;
flags[f]=1;
}
}
if(prev>e) printf("%d\n",x[prev]);
}
return 0;
}
