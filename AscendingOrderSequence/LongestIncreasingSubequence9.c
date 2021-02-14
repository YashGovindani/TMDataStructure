#include<stdio.h>
int main()
{
int e,f,lis;
int x[9]={12,3,92,-3,76,54,12,93,78};
int counts[9]={1,1,1,1,1,1,1,1,1};
lis=1;
for(f=1;f<=8;f++)
{
for(e=0;e<f;e++)
{
if(x[f]>x[e])
{
if(counts[e]+1>counts[f])
{
counts[f]=counts[e]+1;
if(counts[f]>lis) lis=counts[f];
}
}
}
}
printf("Length of Longest Increasing Subsequence is %d\n",lis);
return 0;
}
