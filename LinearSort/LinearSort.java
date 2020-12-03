import java.io.*;

interface Comparator
{
int compare(Object left,Object right);
}

class LinearSort
{
public static <T> void linearSort(T x[],Comparator comparator)
{
int iep,oep,e,f;
T g;
iep=x.length-1;
oep=x.length-2;
e=0;
while(e<=oep)
{
f=e+1;
while(f<=iep)
{
if(comparator.compare((Object)x[f],(Object)x[e])<0)
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
}

class LinearSortTester
{
public static void main(String args[])
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
Integer x[],y,req;
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
LinearSort.linearSort(x,(left,right)->{return (int)left-(int)right;});
for(y=0;y<req;y++) System.out.println(x[y]);
}
}
