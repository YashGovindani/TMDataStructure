import java.io.*;
interface Comparator
{
int compare(Object left,Object right);
}
class SelectionSort
{
public static <T> void selectionSort(T x[],Comparator comparator)
{
int size,oep,iep,e,f,si;
T g;
size=x.length;
oep=size-2;
iep=size-1;
for(e=0;e<=oep;e++)
{
for(si=e,f=e+1;f<=iep;f++) if(comparator.compare((Object)x[f],(Object)x[si])<0) si=f;
g=x[e];
x[e]=x[si];
x[si]=g;
}
}
}
class SelectionSortTester
{
public static void main(String args[])
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
Integer x[],req,y;
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
x=new Integer[req];
for(y=0;y<req;y++)
{
try
{
System.out.print("Enter a number : ");
x[y]=Integer.parseInt(br.readLine());
}catch(IOException ioException)
{
System.out.println(ioException);
}catch(NumberFormatException nfe)
{
System.out.println(nfe);
}
}
SelectionSort.selectionSort(x,(left,right)->{return (int)left-(int)right;});
for(y=0;y<req;y++) System.out.println(x[y]);
}
}
