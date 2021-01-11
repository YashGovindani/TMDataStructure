#include<stdio.h>
#include<stdlib.h>
typedef struct _node
{
int num;
struct _node *next;
}Node;
int main()
{
int x[10],y,i,lb,ub,size,m,largest,smallest,range,index;
Node **lists;
Node *node;
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
// logic to sort
// logic to find largest and smallest
largest=x[lb];
smallest=x[lb];
for(y=lb+1;y<=ub;y++)
{
if(x[y]>largest) largest=x[y];
if(x[y]<smallest) smallest=x[y];
}
range=largest-smallest+1;
lists=(Node **)malloc(sizeof(Node *)*range);
for(y=lb;y<=ub;y++)
{
index=x[y]-smallest;
// insert in list
node=(Node *)malloc(sizeof(Node));
node->num=x[y];
if(!lists[index])
{
node->next=NULL;
lists[index]=node;
}
else
{
node->next=lists[index];
lists[index]=node;
}
}
// put back
for(y=0,i=lb;y<range;y++)
{
for(node=lists[y];node;node=lists[y],i++)
{
lists[y]=node->next;
x[i]=node->num;
free(node);
}
}
// output
for(y=0;y<=m;y++) printf("%d\n",x[y]);
return 0;
}
