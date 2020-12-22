import java.io.*;
interface Comparator
{
int compare(Object left,Object right);
}
class MergeSort
{
public static <T> void merge(T x[],int lb1,int ub1,int lb2,int ub2,Comparator comparator)
{
Object tmp[];
int size1,size2,size3,i1,i2,i3,lb3,ub3;
size1=ub1-lb1+1;
size2=ub2-lb2+1;
size3=size1+size2;
tmp=new Object[size3];
lb3=0;
ub3=size3-1;
i1=lb1;
i2=lb2;
i3=lb3;
while(i1<=ub1 && i2<=ub2)
{
if(comparator.compare(x[i1],x[i2])<0)
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
for(i1=lb1,i3=lb3;i1<=ub1;i1++,i3++) x[i1]=(T)tmp[i3];
for(i2=lb2;i2<=ub2;i2++,i3++) x[i2]=(T)tmp[i3];
}
public static <T> void mergeSort(T x[],int lowerBound,int upperBound,Comparator comparator)
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
merge(x,lb1,ub1,lb2,ub2,comparator);
}
}
public static void main(String args[])
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
Integer x[];
int y,m,req;
req=-1;
try
{
System.out.print("Enter your requirement : ");
req=Integer.parseInt(br.readLine());
}catch(IOException ioException)
{
System.out.println(ioException);
}catch(NumberFormatException nfe)
{
System.out.println(nfe);
}
if(req<=0)
{
System.out.println("Invalid requirement : "+req);
return;
}
x=new Integer[req];
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
MergeSort.mergeSort(x,0,m,(left,right)->{return (int)left-(int)right;});
for(y=0;y<=m;y++) System.out.println(x[y]);
}
}
