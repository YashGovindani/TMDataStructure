import java.io.*;
class BubbleSort1
{
public static void main(String args[])
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
int x[],m,y,e,f,g,req;
req=5;
x=new int[req];
m=req-2;
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
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
e++;
f++;
}
m--;
}
for(y=0;y<req;y++) System.out.println(x[y]);
}
}