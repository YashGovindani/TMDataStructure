import java.io.*;

class LinearSort1
{
public static void main(String args[])
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
int x[],y,iep,oep,g,m,e,f;
m=5;
x=new int[m];
for(y=0;y<m;y++)
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
oep=m-2;
iep=m-1;
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
for(y=0;y<m;y++) System.out.println(x[y]);
}
}
