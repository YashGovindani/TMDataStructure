// Sliding Window
#include<stdio.h>

int main()
{
int x[]={10,2,7,6,9,3};
int ei,si,sum,requiredSum;
requiredSum=23;
for(si=0,ei=0,sum=0;ei<=5;ei++)
{
sum+=x[ei];
if(sum==requiredSum) break;
if(sum>requiredSum)
{
sum-=x[si];
si++;
if(sum==requiredSum) break;
}
}
if(sum==requiredSum) printf("%d,%d\n",si,ei);
else printf("Sub array with sum=%d does not exist\n",requiredSum);
return 0;
}
