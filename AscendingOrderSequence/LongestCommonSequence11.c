#include<stdio.h>
#include<math.h>

int main()
{
int x[4]={65,66,67,68};
int lenX=4;
int xEP,e,j,num;
int upperBoundX=lenX-1;
xEP=pow(2,lenX)-1;
num=1;
while(num<=xEP)
{
for(e=upperBoundX;e>=0;e--)
{
j=num>>e;
if(j&1) printf("%c",x[3-e]);
}
printf("\n");
num++;
}
return 0;
}
