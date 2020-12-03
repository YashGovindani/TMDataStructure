import java.io.*;
class InsertionSort1
{
public static void main(String args[])
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
int x[],y,e,f,m,req,num;
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
}catch(NumberFormatException nfe)
{
System.out.println(nfe);
}
}
e=1;
while(e<=m)
{
num=x[e];
f=e-1;
while(f>=0 && x[f]>num)
{
x[f+1]=x[f];
f--;
}
x[f+1]=num;
e++;
}
for(y=0;y<=m;y++) System.out.println(x[y]);
}
}
