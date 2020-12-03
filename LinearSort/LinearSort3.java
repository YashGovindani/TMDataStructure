import java.io.*;

class LinearSort3
{
public static void linearSort(int x[])
{
int iep,oep,g,e,f;
iep=x.length-1;
oep=x.length-2;
e=0;
while(e<=oep)
{
f=e+1;
while(f<=iep)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
f++;
}
e++;
}
}
public static void main(String args[])
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
int x[],y,req;
req=0;
try
{
System.out.println("Enter your requirement : ");
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
linearSort(x);
for(y=0;y<req;y++) System.out.println(x[y]);
}
}
