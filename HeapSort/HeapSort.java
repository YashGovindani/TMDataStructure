import java.io.*;
interface Comparator
{
int compare(Object left,Object right);
}
class HeapSort
{
public static <T> void convertToHeap(T x[],int lb,int ub,Comparator comparator)
{
int y,ri,ci,diff;
T g;
diff=lb;
ub-=lb;
lb=0;
y=lb+1;
while(y<=ub)
{
ci=y;
while(ci>0)
{
ri=(ci-1)/2;
if(comparator.compare(x[ci+diff],x[ri+diff])>0)
{
g=x[ci+diff];
x[ci+diff]=x[ri+diff];
x[ri+diff]=g;
ci=ri;
}else break;
}
y++;
}
}
public static <T> void heapSort(T x[],int lb,int ub,Comparator comparator)
{
int y,ri,lci,rci,swi,diff;
T g;
diff=lb;
ub-=lb;
lb=0;
convertToHeap(x,lb+diff,ub+diff,comparator);
// implementing heap sort
y=ub;
while(y>lb)
{
g=x[lb+diff];
x[lb+diff]=x[y+diff];
x[y+diff]=g;
y--;
// adjusting heap
ri=lb;
while(ri<y)
{
lci=ri*2+1;
if(lci>y) break;
rci=lci+1;
if(rci>y) swi=lci;
else
{
if(comparator.compare(x[lci+diff],x[rci+diff])>0) swi=lci;
else swi=rci;
}
if(comparator.compare(x[swi+diff],x[ri+diff])>0)
{
g=x[swi+diff];
x[swi+diff]=x[ri+diff];
x[ri+diff]=g;
ri=swi;
}else break;
}
}
}
public static void main(String args[])
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
Integer x[];
int y,req,m;
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
m=req-1;
for(y=0;y<=m;y++)
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
heapSort(x,1,m,(left,right)->{return ((int)left)-((int)right);});
for(y=0;y<=m;y++) System.out.println(x[y]);
}
}
