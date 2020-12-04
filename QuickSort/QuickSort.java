import java.io.*;
interface Comparator
{
int compare(Object left,Object right);
}
class QuickSort
{
public static <T> void quickSort(T x[],int lowerBound,int upperBound,Comparator comparator)
{
int stack[][],top,pp,lb,ub,e,f,size,m;
T g;
pp=-1;
size=upperBound-lowerBound+1;
stack=new int[size][2];
m=size-1;
top=size;
top--;
stack[top][0]=lowerBound;
stack[top][1]=upperBound;
while(top!=size)
{
lb=stack[top][0];
ub=stack[top][1];
top++;
e=lb;
f=ub;
while(e<f)
{
while(comparator.compare(x[e],x[lb])<=0) e++;
while(comparator.compare(x[f],x[lb])>0) f--;
if(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
else
{
g=x[f];
x[f]=x[lb];
x[lb]=g;
pp=f;
}
}
if(pp+1<ub)
{
top--;
stack[top][0]=pp+1;
stack[top][1]=ub;
}
if(lb<pp-1)
{
top--;
stack[top][0]=lb;
stack[top][1]=pp-1;
}
}
}
public static void main(String args[])
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
Integer x[],y,req,m;
try
{
System.out.print("Enter your requirement : ");
req=Integer.parseInt(br.readLine());
}catch(IOException ioException)
{
System.out.println(ioException);
return;
}catch(NumberFormatException nfe)
{
System.out.println(nfe);
return;
}
m=req-1;
x=new Integer[req];
for(y=0;y<=m;y++)
{
System.out.print("Enter a number : ");
try
{
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
quickSort(x,0,m,(left,right)->{return (int)left-(int)right;});
for(y=0;y<=m;y++) System.out.println(x[y]);
}
}
