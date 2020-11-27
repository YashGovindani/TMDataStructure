#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
 * ptr for storing base address
 * cs represents collection size
 * es represents size of one element
 */
void bubbleSort(void *ptr,int cs,int es,int (*p2f)(void *,void *))
{
int e,f,m,w;
void *a,*b,*c;
c=(void *)malloc(es);
m=cs-2;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
a=ptr+(f*es);
b=ptr+(e*es);
w=p2f(a,b);
if(w<0)
{
memcpy(c,a,es); // for swapping
memcpy(a,b,es);
memcpy(b,c,es);
}
e++;
f++;
}
m--;
}
free(c);
}

struct Student
{
int rollNumber;
char name[21];
};

int myComparator(void *left,void *right)
{
struct Student *i,*j;
i=(struct Student *)left;
j=(struct Student *)right;
return (i->rollNumber)-(j->rollNumber);
}

int main()
{
struct Student *x;
int requirement,y;
printf("Enter requirement : ");
scanf("%d",&requirement);
fflush(stdin);
if(requirement<=0)
{
printf("Invalid requirement\n");
return 0;
}
x=(struct Student *)malloc(sizeof(struct Student)*requirement);
if(x==NULL)
{
printf("Unable to allocate memory for %d students\n",requirement);
return 0;
}
for(y=0;y<requirement;y++)
{
printf("Enter a number : ");
scanf("%d",&(x[y].rollNumber));
fflush(stdin);
}
bubbleSort(x,requirement,sizeof(struct Student),myComparator);
for(y=0;y<requirement;y++)
{
printf("%d\n",x[y].rollNumber);
}
free(x);
return 0;
}
