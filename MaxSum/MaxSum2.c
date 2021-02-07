#include<stdio.h>

int maxSum(int *x,int length)
{
int m,gmax,lmax,i,g;
for(i=1,gmax=x[0],lmax=x[0],m=length-1;i<=m;i++)
{
g=lmax+x[i];
if(x[i]>g) lmax=x[i];
else lmax=g;
if(lmax>gmax) gmax=lmax;
}
return gmax;
}

int main()
{
int x[]={10,-2,7,-6,-9,3};
printf("%d\n",maxSum(x,6));
return 0;
}
