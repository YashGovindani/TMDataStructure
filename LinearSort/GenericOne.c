#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void linearSort(void *ptr,int cs,int es,int (*p2f)(void *,void *))
{
int e,f,g,oep,iep,w;
void *a,*b,*c;
c=(void *)malloc(es);
oep=cs-2;
iep=cs-1;
for(e=0;e<=oep;e++)
{
for(f=e+1;f<=iep;f++)
{
a=ptr+(f*es);
b=ptr+(e*es);
w=p2f(a,b);
if(w<0)
{
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
}
}
}
free(c);
}

int myComparator(void *left,void *right)
{
int *a,*b;
a=(int *)left;
b=(int *)right;
return (*a)-(*b);
}

int main()
{
int *x;
int y,requirement;
printf("Enter requirement : ");
scanf("%d",&requirement);
fflush(stdin);
if(requirement<=0)
{
printf("Invalid requirement\n");
return 0;
}
x=(int *)malloc(sizeof(int)*requirement);
if(x==NULL)
{
printf("Cannot allocate memeory for %d numbers\n",requirement);
return 0;
}
for(y=0;y<requirement;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
}
linearSort(x,requirement,sizeof(int),myComparator);
for(y=0;y<requirement;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}
