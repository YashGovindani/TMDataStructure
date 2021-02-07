#include<stdio.h>
#include<stdlib.h>
int _fibo(int k,int *values,int *foundTill)
{
if(k<=1) return k;
if(k<=*foundTill) return values[k];
values[k]=_fibo(k-1,values,foundTill)+_fibo(k-2,values,foundTill);
*foundTill=k;
return values[k];
}

int fibo(int k)
{
int *values,toBeReturned,foundTill;
values=(int *)malloc(sizeof(int)*(k+1));
foundTill=1;
toBeReturned=_fibo(k,values,&foundTill);
free(values);
return toBeReturned;
}

int main()
{
int k;
printf("Enter element number : ");
scanf("%d",&k);
printf("%d\n",fibo(k));
return 0;
}
