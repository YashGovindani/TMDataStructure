// Bruteforce
#include<stdio.h>

int maxSum(int *x,int length)
{
int m,max,sum,i,j;
m=length-1;
max=x[0];
for(i=0;i<=m;i++)
{
sum=0;
for(j=i;j<=m;j++)
{
sum+=x[j];
if(sum>max) max=sum;
}
}
return max;
}

int main()
{
int x[]={10,-2,7,-6,-9,3};
printf("%d\n",maxSum(x,6));
return 0;
}
