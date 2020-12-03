import java.io.*;
class SelectionSort3
{
public static void selectionSort(int x[])
{
int size,oep,iep,e,f,g,si;
size=x.length;
oep=size-2;
iep=size-1;
for(e=0;e<=oep;e++)
{
for(si=e,f=e+1;f<=iep;f++) if(x[f]<x[si]) si=f;
g=x[e];
x[e]=x[si];
x[si]=g;
}
}
public static void main(String args[])
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
int x[],req,y;
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
x=new int[req];
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
selectionSort(x);
for(y=0;y<req;y++) System.out.println(x[y]);
}
}
