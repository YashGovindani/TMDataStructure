#include<stdio.h>
int main()
{
int x,y,z,j,k;
x=0;
y=1;
printf("Enter element number : ");
scanf("%d",&k);
j=1;
while(j<k)
{
z=x+y;
x=y;
y=z;
j++;
}
printf("%d\n",y);
return 0;
}
