#include<stdio.h>
int main()
{
int x[10],y,ci,ri,lci,rci,swi,g;
y=0;
while(y<=9)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
fflush(stdin);
fpurge(stdin); // for mac OS
y++;
}
// logic to convert the contents of the array to heap
y=1;
while(y<=9)
{
ci=y;
while(ci>0)
{
ri=(ci-1)/2;
if(x[ci]>x[ri])
{
g=x[ci];
x[ci]=x[ri];
x[ri]=g;
ci=ri;
}else break;
}
y++;
}
// implementing heap sort
y=9;
while(y>0)
{
g=x[0];
x[0]=x[y];
x[y]=g;
y--;
ri=0;
while(ri<y)
{
lci=(ri*2)+1;
if(lci>y) break;
rci=lci+1;
if(rci>y) swi=lci;
else
{
if(x[lci]>x[rci]) swi=lci;
else swi=rci;
}
if(x[swi]>x[ri])
{
g=x[swi];
x[swi]=x[ri];
x[ri]=g;
ri=swi;
}else break;
}
}
for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}
