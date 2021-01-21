#include<stdio.h>
#include<stdlib.h>
void mergeForInversionCount(int *x,int lb,int mid,int ub,int *count)
{
int i1,i2,i3,tmpSize,lb1,lb2,lb3,ub1,ub2,ub3;
int *tmp;
tmpSize=ub-lb+1;
tmp=(int *)malloc(sizeof(int)*tmpSize);
lb1=lb;
ub1=mid;
lb2=mid+1;
ub2=ub;
lb3=0;
ub3=tmpSize-1;
i1=lb1;
i2=lb2;
i3=lb3;
while(i1<=ub1 && i2<=ub2)
{
if(x[i1]<x[i2])
{
tmp[i3]=x[i1];
i1++;
}
else
{
(*count)+=ub1-i1+1;
tmp[i3]=x[i2];
i2++;
}
i3++;
}
while(i1<=ub1)
{
tmp[i3]=x[i1];
i3++;
i1++;
}
while(i2<=ub2)
{
tmp[i3]=x[i2];
i3++;
i2++;
}
i1=lb1;
i3=0;
while(i1<=ub2)
{
x[i1]=tmp[i3];
i3++;
i1++;
}
free(tmp);
}

void _inversionCount(int *x,int low,int high,int *count)
{
int mid;
if(low<high)
{
mid=(low+high)/2;
_inversionCount(x,low,mid,count);
_inversionCount(x,mid+1,high,count);
mergeForInversionCount(x,low,mid,high,count);
}
}

int getInversionCount(int *x,int low,int high)
{
int count;
count=0;
_inversionCount(x,low,high,&count);
return count;
}

int collaborativeFilter(int *rankingOne,int *rankingTwo,int low,int high)
{
int size,i,count;
int *tmp;
size=high-low+1;
tmp=(int *)malloc(sizeof(int)*size);
for(i=low;i<=high;i++) tmp[rankingOne[i]-1]=rankingTwo[i];
count=getInversionCount(tmp,low,high);
free(tmp);
return count;
}

int main()
{
int y;
int x1[]={3,1,2,4,5};
int x2[]={5,4,2,1,3};
printf("%d\n",collaborativeFilter(x1,x2,0,4));
return 0;
}
