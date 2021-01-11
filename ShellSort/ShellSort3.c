#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void shellSort(void *x,int lb,int ub,int elementSize,int (*p2f)(void *,void *))
{
int size,diff,e,f;
void *data;
data=(void *)malloc(elementSize);
size=ub-lb+1;
diff=size/2;
while(diff>=1)
{
e=lb+diff;
while(e<=ub)
{
memcpy(data,x+(elementSize*e),elementSize);
f=e-diff;
while(f>=lb && p2f(x+(elementSize*f),data)>0)
{
memcpy(x+(elementSize*(f+diff)),x+(elementSize*f),elementSize);
f-=diff;
}
memcpy(x+(elementSize*(f+diff)),data,elementSize);
e+=diff;
}
diff/=2;
}
}

int comparator(void *left,void *right)
{
return (*((int *)left))-(*((int *)right));
}

int main()
{
int x[10],y,m;
m=10-1;
for(y=0;y<=m;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
}
shellSort(x,1,m,sizeof(int),comparator);
for(y=0;y<=m;y++) printf("%d\n",x[y]);
return 0;
}
