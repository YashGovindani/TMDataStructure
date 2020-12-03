#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insertionSort(void *data,int cs,int es,int (*p2f)(void *,void *))
{
int m,e,f;
void *block;
block=(void *)malloc(es);
m=cs-1;
e=1;
while(e<=m)
{
memcpy(block,data+(e*es),es);
f=e-1;
while(f>=0 && p2f(data+(f*es),block)>0)
{
memcpy(data+((f+1)*es),data+(f*es),es);
f--;
}
memcpy(data+((f+1)*es),block,es);
e++;
}
free(block);
}

int comparator(void *left,void *right)
{
int *a,*b;
a=(int *)left;
b=(int *)right;
return (*a)-(*b);
}

int main()
{
int *x;
int y,m,req;
printf("Enter requirement : ");
scanf("%d",&req);
fflush(stdin);
if(req<=0)
{
printf("Invalid requirement : %d\n",req);
return 0;
}
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Unable to allocate memory for requirement : %d\n",req);
return 0;
}
m=req-1;
for(y=0;y<=m;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
}
insertionSort(x,req,sizeof(int),comparator);
for(y=0;y<=m;y++) printf("%d\n",x[y]);
free(x);
return 0;
}
