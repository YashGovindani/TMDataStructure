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
public static void main(String args[])
{
Queue <Integer>queue;
queue=new Queue<>();
int ch;
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
while(true)
{
System.out.println("1. Add to queue");
System.out.println("2. Remove from queue");
System.out.println("3. Exit");
System.out.print("Enter your choice : ");
try
{
ch=Integer.parseInt(br.readLine());
if(ch==1)
{
System.out.print("Enter a number : ");
queue.add(Integer.parseInt(br.readLine()));
}
else if(ch==2)
{
if(queue.isEmpty()) System.out.println("Queue is empty");
else System.out.print(queue.remove()+" removed from queue");
}
if(ch==3) break;
}catch(IOException ioException)
{
System.out.println(ioException.getMessage());
}catch(NumberFormatException nfe)
{
System.out.println(nfe.getMessage());
}
}
}
}
