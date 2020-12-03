import java.io.*;

interface Comparator
{
int compare(Object left,Object right);
}

class BubbleSort<T>
{
public void bubbleSort(T x[],Comparator comparator)
{
int m,e,f;
T g;
m=x.length-2;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
if(comparator.compare((Object)x[f],(Object)x[e])<0)
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
}
}

class BubbleSortTester
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
new BubbleSort<Integer>().bubbleSort(x,(left,right)->{return (int)left-(int)right;});
for(y=0;y<req;y++) System.out.println(x[y]);
}
}
