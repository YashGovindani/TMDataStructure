// Bruteforce
#include<stdio.h>

int main()
{
int x[]={10,2,7,6,9,3};
int i,j,sum,requiredSum;
requiredSum=23;
for(i=0;i<=5;i++)
{
for(j=i,sum=0;j<=5;j++)
{
sum+=x[j];
if(sum==requiredSum)
{
printf("%d,%d\n",i,j);
return 0;
}
if(sum>requiredSum) break;
}
}
printf("Sub array with sum=%d does not exist\n",requiredSum);
return 0;
}
