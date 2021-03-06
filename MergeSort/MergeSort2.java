import java.io.*;
class MergeSort2
{
public static void merge(int x[],int lb1,int ub1,int lb2,int ub2)
{
int tmp[];
int size1,size2,size3,i1,i2,i3,lb3,ub3;
size1=ub1-lb1+1;
size2=ub2-lb2+1;
size3=size1+size2;
tmp=new int[size3];
lb3=0;
ub3=size3-1;
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
for(i1=lb1,i3=lb3;i1<=ub1;i1++,i3++) x[i1]=tmp[i3];
for(i2=lb2;i2<=ub2;i2++,i3++) x[i2]=tmp[i3];
}
public static void mergeSort(int x[],int lowerBound,int upperBound)
{
int lbStack1[],ubStack1[],lbStack2[],ubStack2[];
int a,b,mid,lb1,lb2,ub1,ub2,top1,top2,size;
size=upperBound-lowerBound+1;
top1=size;
top2=size;
lbStack1=new int[size];
ubStack1=new int[size];
lbStack2=new int[size];
ubStack2=new int[size];
// push lowerBound,upperBound on stack1
top1--;
lbStack1[top1]=lowerBound;
ubStack1[top1]=upperBound;
while(top1!=size) // stack1 is not empty
{
// pop from stack1 in a,b
a=lbStack1[top1];
b=ubStack1[top1];
top1++;
//push a,b on stack2
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
while(top2!=size) // stack2 is not empty
{
// pop from stack2 in lb1,ub2
lb1=lbStack2[top2];
ub2=ubStack2[top2];
top2++;
ub1=(lb1+ub2)/2;
lb2=ub1+1;
merge(x,lb1,ub1,lb2,ub2);
}
}
public static void main(String args[])
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
int x[];
int y,m,req;
req=10;
x=new int[req];
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
mergeSort(x,0,m);
for(y=0;y<=m;y++) System.out.println(x[y]);
}
}
