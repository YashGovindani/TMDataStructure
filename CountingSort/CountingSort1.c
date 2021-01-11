#include<stdio.h>
#include<stdlib.h>
int main()
{
int x[10],y,i,largest;
int *tmp;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fpurge(stdin);
}
// logic to find largest starts
largest=x[0];
for(y=1;y<=9;y++) if(x[y]>largest) largest=x[y];
// logic to find largest ends
// allocating memory for largest+1 elements
tmp=(int *)malloc(sizeof(int)*(largest+1));
// populating tmp with 0
for(y=0;y<=largest;y++) tmp[y]=0;
for(y=0;y<=9;y++) tmp[x[y]]++;
for(y=0,i=0;y<=largest;y++)
{
while(tmp[y]>0)
{
x[i]=y;
i++;
tmp[y]--;
}
}
for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}
