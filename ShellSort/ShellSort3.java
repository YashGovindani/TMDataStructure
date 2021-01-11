import java.io.*;
interface Comparator
{
int compare(Object left,Object right);
}
class ShellSort3
{
public static <T> void shellSort(T x[],int lb,int ub,Comparator comparator)
{
int size,diff,e,f;
T data;
size=ub-lb+1;
diff=size/2;
while(diff>=1)
{
e=lb+diff;
while(e<=ub)
{
data=x[e];
f=e-diff;
while(f>=lb && comparator.compare(x[f],data)>0)
{
x[f+diff]=x[f];
f-=diff;
}
x[f+diff]=data;
e+=diff;
}
diff/=2;
}
}
public static void main(String args[])
{
BufferedReader br;
Integer x[];
int y,e,f,num,m,size,ub,lb,diff;
br=new BufferedReader(new InputStreamReader(System.in));
x=new Integer[10];
m=10-1;
lb=0;
ub=m;
for(y=0;y<=m;y++)
{
try
{
System.out.print("Enter a number : ");
x[y]=Integer.parseInt(br.readLine());
}catch(IOException ioException)
{
System.out.println(ioException.getMessage());
}catch(NumberFormatException nfe)
{
System.out.println(nfe.getMessage());
}
}
ShellSort3.shellSort(x,1,m,(left,right)->{return (int)left-(int)right;});
for(y=0;y<=m;y++) System.out.println(x[y]);
}
}
