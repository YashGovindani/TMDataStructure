import java.io.*;
class HeapSort1
{
public static void main(String args[])
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
int x[];
int g,ri,ci,y,lci,rci,swi,req,m;
req=6;
m=req-1;
x=new int[req];
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
// logic to convert array to heap
y=1;
while(y<=m)
{
ci=y;
while(ci>0)
{
ri=(ci-1)/2;
if(x[ci]>x[ri])
{
g=x[ci];
x[ci]=x[ri];
x[ri]=g;
ci=ri;
}else break;
}
y++;
}
// implementing heap sort
y=m;
while(y>0)
{
g=x[0];
x[0]=x[y];
x[y]=g;
y--;
ri=0;
while(ri<y)
{
lci=2*ri+1;
if(lci>y) break;
rci=lci+1;
if(rci>y) swi=lci;
else
{
if(x[lci]>x[rci]) swi=lci;
else swi=rci;
}
if(x[swi]>x[ri])
{
g=x[swi];
x[swi]=x[ri];
x[ri]=g;
ri=swi;
}else break;
}
}
for(y=0;y<=m;y++) System.out.println(x[y]);
}
}
