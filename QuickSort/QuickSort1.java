import java.io.*;
class QuickSort1
{
public static void main(String args[])
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
int x[],stack[][],top,pp,lowerBound,upperBound,lb,ub,e,f,g,y,req,m;
pp=-1;
req=5;
m=req-1;
lowerBound=0;
upperBound=m;
x=new int[req];
stack=new int[req][2];
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
top=req;
top--;
stack[top][0]=lowerBound;
stack[top][1]=upperBound;
while(top!=req)
{
lb=stack[top][0];
ub=stack[top][1];
top++;
e=lb;
f=ub;
while(e<f)
{
while(x[e]<=x[lb] && e<ub) e++;
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
for(y=0;y<=m;y++) System.out.println(x[y]);
}
}
