#include<stdio.h>
#include<math.h>

int main()
{
int y[4]={65,66,67,68};
int lenY=4;
int yEP,e,j,num2;
int upperBoundY=lenY-1;
yEP=pow(2,lenY)-1;
num2=1;
while(num2<=yEP)
{
for(e=upperBoundY;e>=0;e--)
{
j=num2>>e;
if(j&1) printf("%c",y[upperBoundY-e]);
}
printf("\n");
num2++;
}
return 0;
}
