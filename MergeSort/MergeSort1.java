import java.io.*;
class MergeSort1
{
public static void main(String args[])
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
int x[],tmp[],lbStack1[],ubStack1[],lbStack2[],ubStack2[];
int y,m,req,a,b,mid,lb1,lb2,lb3,ub1,ub2,ub3,i1,i2,i3,top1,top2;
req=10;
x=new int[req];
tmp=new int[req];
lbStack1=new int[req];
ubStack1=new int[req];
lbStack2=new int[req];
ubStack2=new int[req];
m=req-1;
for(y=0;y<=m;y++)
{
try
{
System.out.print("Enter a number : ");
x[y]=Integer.parseInt(br.readLine());
}catch(IOException ioException)
{
System.out.println(ioException);
return;
}catch(NumberFormatException nfe)
{
System.out.println(nfe);
return;
}
}
// merge sort logic starts
top1=req;
top2=req;
// push 0,m on stack1
top1--;
lbStack1[top1]=0;
ubStack1[top1]=m;
while(top1!=req) // stack1 is not empty
{
// pop from stack1 in a,b
a=lbStack1[top1];
b=ubStack1[top1];
top1++;
// push a,b on stack2
top2--;
lbStack2[top2]=a;
ubStack2[top2]=b;
// calculate mid
mid=(a+b)/2;
if(a<mid)
{
// push a,mid on stack1
top1--;
lbStack1[top1]=a;
ubStack1[top1]=mid;
}
if(mid+1<b)
{
// push mid+1,b on stack1
top1--;
lbStack1[top1]=mid+1;
ubStack1[top1]=b;
}
}
while(top2!=req) // stack2 is not empty
{
// pop from stack2 in lb1,ub2
lb1=lbStack2[top2];
ub2=ubStack2[top2];
top2++;
ub1=(lb1+ub2)/2;
lb2=ub1+1;
// logic to merge starts
lb3=lb1;
ub3=ub2;
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
tmp[i3]=x[i2];
i2++;
}
i3++;
}
while(i1<=ub1)
{
tmp[i3]=x[i1];
i1++;
i3++;
}
while(i2<=ub2)
{
tmp[i3]=x[i2];
i2++;
i3++;
}
// put back
for(i3=lb3;i3<=ub3;i3++) x[i3]=tmp[i3];
// logic to merge ends
}
// merge sort logic ends
for(y=0;y<=m;y++) System.out.println(x[y]);
}
}
