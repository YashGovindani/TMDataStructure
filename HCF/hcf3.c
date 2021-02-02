// euclidean algorithm iterative
#include<stdio.h>
#include<stdlib.h>

int hcf(int a,int b)
{
int g;
if(a<b)
{
g=a;
a=b;
b=g;
}
while(b)
{
g=a;
a=b;
b=g%b;
}
return a;
}

int main(int argc,char *argv[])
{
int a,b;
a=atoi(argv[1]);
b=atoi(argv[2]);
printf("hcf(%d,%d)=%d\n",a,b,hcf(a,b));
return 0;
}
