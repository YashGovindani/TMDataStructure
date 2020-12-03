import java.io.*;
class SelectionSort1
{
public static void main(String args[])
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
int x[],req,y,e,f,g,si,oep,iep;
req=5;
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
oep=req-2;
iep=req-1;
for(e=0;e<=oep;e++)
{
for(si=e,f=e+1;f<=iep;f++) if(x[f]<x[si]) si=f;
g=x[e];
x[e]=x[si];
x[si]=g;
}
for(y=0;y<req;y++) System.out.println(x[y]);
}
}
