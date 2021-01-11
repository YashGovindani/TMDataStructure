#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node
{
int num;
struct _node *next;
}Node;

int main()
{
Node *lists[10];
Node *n1,*n2;
Node *node;
int x[10];
int i,index,y,size,m,lb,ub,dc,factor1,factor2,largest;
for(y=0;y<=9;y++) lists[y]=NULL;
size=10;
m=size-1;
// input
for(y=0;y<=m;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fpurge(stdin);
}
lb=0;
ub=m;
// logic to find largest
largest=x[lb];
for(y=lb+1;y<=ub;y++)
{
if(x[y]>largest) largest=x[y];
}
printf("Largest : %d\n",largest);
// logic to calculate number of digits
dc=1;
i=largest;
while(i>9)
{
dc++;
i/=10;
}
printf("Number of digits : %d\n",dc);
// logic to calculate factor for generating keys
factor1=1;
for(y=0;y<dc;y++,factor1*=10);
factor2=factor1/10;
printf("Factor1 : %d, Factor2 : %d\n",factor1,factor2);
// logic to sort
// spread in lists
for(y=lb;y<=ub;y++)
{
index=(x[y]%factor1)/factor2;
printf("Inserting in list : %d\n",index);
// logic to insert in list
node=(Node *)malloc(sizeof(Node));
node->num=x[y];
node->next=NULL;
if(!lists[index]) lists[index]=node;
else
{
n2=NULL;
n1=lists[index];
while(n1 && n1->num<node->num)
{
n2=n1;
n1=n1->next;
}
if(!n1) n2->next=node; // insert at end
else
{
if(!n2) // insert at start
{
node->next=n1;
lists[index]=node;
}
else 
{
node->next=n1;
n2->next=node;
}
}
}
}
printf("Spreaded in lists");
// put back
for(y=0,i=lb;y<=9;y++)
{
n1=lists[y];
while(n1)
{
n2=n1;
n1=n1->next;
x[i]=n2->num;
i++;
free(n2);
}
}
// output
for(y=0;y<=m;y++) printf("%d\n",x[y]);
return 0;
}
