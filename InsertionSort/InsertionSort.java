import java.io.*;
interface Comparator
{
int compare(Object left,Object right);
}
class InsertionSort
{
public static <T> void insertionSort(T x[],Comparator comparator)
{
int e,f,m;
T block;
m=x.length-1;
e=1;
while(e<=m)
{
block=x[e];
f=e-1;
while(f>=0 && comparator.compare(x[f],block)>0)
{
x[f+1]=x[f];
f--;
}
x[f+1]=block;
e++;
}
}
}
class InsertionSortTester
{
public static void main(String args[])
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
Integer x[],y,e,f,m,req,num;
req=0;
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
}catch(NumberFormatException nfe)
{
System.out.println(nfe);
}
}
InsertionSort.insertionSort(x,(left,right)->{return (int)left-(int)right;});
for(y=0;y<=m;y++) System.out.println(x[y]);
}
}
