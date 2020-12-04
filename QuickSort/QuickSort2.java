import java.io.*;
class QuickSort2
{
public static void quickSort(int x[],int lowerBound,int upperBound)
{
int stack[][],top,pp,lb,ub,e,f,g,size,m;
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
while(x[e]<=x[lb]) e++;
while(x[f]>x[lb]) f--;
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
int x[],y,req,m;
req=5;
m=req-1;
x=new int[req];
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
quickSort(x,0,m);
for(y=0;y<=m;y++) System.out.println(x[y]);
}
}
