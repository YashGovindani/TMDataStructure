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
class RadixSort1
{
public static void main(String args[])
{
try
{
int x[];
int y,e,f,i,num,largest,dc,k;
Object queues[];
BufferedReader br;
br=new BufferedReader(new InputStreamReader(System.in));
x=new int[10];
queues=new Object[10];
for(y=0;y<=9;y++) queues[y]=new Queue<Integer>();
for(y=0;y<=9;y++)
{
System.out.print("Enter a number : ");
x[y]=Integer.parseInt(br.readLine());
}
// logic to find largest
largest=x[0];
for(y=1;y<=9;y++)
{
if(x[y]>largest) largest=x[y];
}
// logic to find number of digits
dc=1;
num=largest;
while(num>9)
{
num/=10;
dc++;
}
// logic to sort
e=10;
f=1;
k=1;
while(k<=dc)
{
// spread out in 10 queues according to digit at kth place
y=0;
while(y<=9)
{
num=x[y];
i=(num%e)/f;
// add the num to ith queue
((Queue<Integer>)queues[i]).add(num);
y++;
}
// collect all numbers from 10 queues and keep it in array
i=0;
y=0;
while(y<=9)
{
while(!((Queue<Integer>)queues[y]).isEmpty())
{
x[i]=((Queue<Integer>)queues[y]).remove();
i++;
}
y++;
}
e*=10;
f*=10;
k++;
}
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
