#include<stdio.h>

int maxSum(int *x,int length,int *si,int *ei)
{
int m,gmax,lmax,i,g;
*si=0;
*ei=0;
for(i=1,gmax=x[0],lmax=x[0],m=length-1;i<=m;i++)
{
g=lmax+x[i];
if(x[i]>g)
{
lmax=x[i];
*si=i;
}
else lmax=g;
if(lmax>gmax)
{
gmax=lmax;
*ei=i;
}
}
return gmax;
}

int main()
{
int x[]={10,-2,7,-6,-9,3};
int si,ei;
printf("%d-->(%d,%d)\n",maxSum(x,6,&si,&ei),si,ei);
return 0;
}
