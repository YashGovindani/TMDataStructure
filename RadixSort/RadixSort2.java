import java.io.*;
class Queue<T>
{
private class QueueNode
{
public T data;
public QueueNode next;
}
private QueueNode start;
private QueueNode end;
private int size;
public Queue()
{
this.start=null;
this.end=null;
this.size=0;
}
public boolean isEmpty()
{
return this.size==0;
}
public void add(T data)
{
QueueNode node;
node=new QueueNode();
node.data=data;
if(this.isEmpty()) this.start=this.end=node;
else
{
this.end.next=node;
this.end=node;
}
this.size++;
}
public T remove()
{
T data=this.start.data;
this.start=this.start.next;
this.size--;
return data;
}
public void clear()
{
this.start=this.end=null;
this.size=0;
}
}
class RadixSort2
{
public static int getLargest(int x[],int lb,int ub)
{
int i,largest;
largest=x[lb];
for(i=lb+1;i<=ub;i++) if(x[i]>largest) largest=x[i];
return largest;
}
public static int getDigitCount(int num)
{
int dc;
dc=1;
if(num<0) num*=-1;
while(num>9)
{
dc++;
num/=10;
}
return dc;
}
public static void spread(int ptr[],int lb,int ub,int e,int f,Object queues[])
{
int num,y,i;
y=lb;
while(y<=ub)
{
num=ptr[y];
i=(num%e)/f;
((Queue<Integer>)queues[i]).add(num);
y++;
}
}
public static void collect(int ptr[],int lb,Object queues[])
{
int i,y;
i=lb;
y=0;
while(y<=9)
{
while(!((Queue<Integer>)queues[y]).isEmpty())
{
ptr[i]=((Queue<Integer>)queues[y]).remove();
i++;
}
y++;
}
}
public static void radixSort(int ptr[],int lb,int ub)
{
int largest,sizw,dc,e,f,i,k,y,num;
Object queues[];
queues=new Object[10];
for(y=0;y<=9;y++) queues[y]=new Queue<Integer>();
for(y=lb-1,i=lb;i<=ub;i++)
{
if(ptr[i]<0)
{
y++;
if(y==i) ptr[y]*=-1;
else
{
num=ptr[y];
ptr[y]=(-1)*ptr[i];
ptr[i]=num;
}
}
}
if(y>lb) radixSort(ptr,lb,y);
for(e=lb,f=y;e<=f;e++,f--)
{
num=(-1)*ptr[e];
ptr[e]=(-1)*ptr[f];
ptr[f]=num;
}
if(y==ub) return;
lb=y+1;
largest=getLargest(ptr,lb,ub);
dc=getDigitCount(largest);
e=10;
f=1;
k=1;
while(k<=dc)
{
RadixSort2.spread(ptr,lb,ub,e,f,queues);
RadixSort2.collect(ptr,lb,queues);
e*=10;
f*=10;
k++;
}
}
public static void main(String args[])
{
try
{
int x[];
int y;
BufferedReader br;
br=new BufferedReader(new InputStreamReader(System.in));
x=new int[10];
for(y=0;y<=9;y++)
{
System.out.print("Enter a number : ");
x[y]=Integer.parseInt(br.readLine());
}
RadixSort2.radixSort(x,1,9);
for(y=0;y<=9;y++) System.out.println(x[y]);
}catch(IOException ioException)
{
System.out.println(ioException.getMessage());
}catch(NumberFormatException nfe)
{
System.out.println(nfe.getMessage());
}
}
}
