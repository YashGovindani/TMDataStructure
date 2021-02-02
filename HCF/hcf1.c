// Bruteforce
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
int a,b,c,d,e,g,hcf,ep;
a=atoi(argv[1]);
b=atoi(argv[2]);

if(b<a)
{
g=a;
a=b;
b=g;
}
if(b%a==0) hcf=a;
else
{
hcf=1;
c=a;
d=b;
for(e=2,ep=c/2;e<=ep && c>1;e++)
{
while(c%e==0 && d%e==0)
{
hcf*=e;
c/=e;
d/=e;
}
}
}
printf("hcf(%d,%d)=%d\n",a,b,hcf);
return 0;
}
