#include<stdio.h>

long myPow(int base,int power)
{
// at current stage the logic works only for positive number and positve power
int subPower;
long subValue1,subValue2;
if(power==1) return base;
subPower=power/2;
subValue1=myPow(base,subPower);
if(power%2) subValue2=subValue1*((long)base);
else subValue2=subValue1;
return subValue1*subValue2;
}

int main()
{
printf("pow(7,9) = %ld\n",myPow(7,9));
return 0;
}
