#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * data stores base address of the data
 * cs represents collection size
 * es represents size of an element
 * p2f stores address of a pointer to comparator
 */

void selectionSort(void *data,int cs,int es,int (*p2f)(void *,void *))
{
int e,f,oep,iep,si,w;
void *a,*b,*c;
c=(void *)malloc(es);
oep=cs-2;
iep=cs-1;
e=0;
while(e<=oep)
{
f=e+1;
si=e;
while(f<=iep)
{
a=data+(f*es);
b=data+(si*es);
w=p2f(a,b);
if(w<0) si=f;
f++;
}
if(si!=e)
{
a=data+(si*es);
b=data+(e*es);
memcpy(c,a,es);
memcpy(a,b,es);
memcpy(b,c,es);
}
e++;
}
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
int y,req,m;
printf("Enter requirement : ");
scanf("%d",&req);
fflush(stdin);
if(req<=0)
{
printf("Invalid requirement : %d\n",req);
return 0;
}
m=req-1;
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Can not allocate memory for requirement : %d\n",req);
return 0;
}
for(y=0;y<=m;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
}
selectionSort(x,req,4,comparator);
for(y=0;y<=m;y++) printf("%d\n",x[y]);
return 0;
}
