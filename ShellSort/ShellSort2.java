import java.io.*;
class ShellSort2
{
public static void shellSort(int x[],int lb,int ub)
{
int size,diff,e,f,num;
size=ub-lb+1;
diff=size/2;
while(diff>=1)
{
e=lb+diff;
while(e<=ub)
{
num=x[e];
f=e-diff;
while(f>=lb && x[f]>num)
{
x[f+diff]=x[f];
f-=diff;
}
x[f+diff]=num;
e+=diff;
}
diff/=2;
}
}
public static void main(String args[])
{
BufferedReader br;
int x[];
int y,e,f,num,m,size,ub,lb,diff;
br=new BufferedReader(new InputStreamReader(System.in));
x=new int[10];
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
ShellSort2.shellSort(x,1,m);
for(y=0;y<=m;y++) System.out.println(x[y]);
}
}
