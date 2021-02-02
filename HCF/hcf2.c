// euclidean algorithm
#include<stdio.h>
#include<stdlib.h>

int _hcf(int a,int b)
{
if(!b) return a;
return _hcf(b,a%b);
}

int hcf(int a,int b)
{
if(a<b) return _hcf(b,a);
return _hcf(a,b);
}

int main(int argc,char *argv[])
{
int a,b;
a=atoi(argv[1]);
b=atoi(argv[2]);
printf("hcf(%d,%d)=%d\n",a,b,hcf(a,b));
return 0;
}
