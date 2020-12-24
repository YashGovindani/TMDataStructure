import java.io.*;
class HeapSort2
{
public static void heapSort(int x[],int lb,int ub)
{
int y,ri,ci,lci,rci,swi,g,diff;
// logic to convert array to heap
diff=lb;
ub-=lb;
lb=0;
y=lb+1;
while(y<=ub)
{
ci=y;
while(ci>lb)
{
ri=(ci-1)/2;
if(x[ci+diff]>x[ri+diff])
{
g=x[ci+diff];
x[ci+diff]=x[ri+diff];
x[ri+diff]=g;
ci=ri;
}else break;
}
y++;
}
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
if(x[lci+diff]>x[rci+diff]) swi=lci;
else swi=rci;
}
if(x[swi+diff]>x[ri+diff])
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
int x[];
int y,req,m;
req=6;
x=new int[req];
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
heapSort(x,1,m);
for(y=0;y<=m;y++) System.out.println(x[y]);
}
}
