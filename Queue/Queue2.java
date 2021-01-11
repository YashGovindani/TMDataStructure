import java.io.*;
class Queue2
{
private class QueueNode
{
public int num;
public QueueNode next;
public QueueNode()
{
this.num=0;
this.next=null;
}
}
private QueueNode start;
private QueueNode end;
private int size;
public Queue2()
{
this.start=null;
this.end=null;
this.size=0;
}
public boolean isEmpty()
{
return this.size==0;
}
public void add(int num)
{
QueueNode node;
node=new QueueNode();
node.num=num;
if(this.isEmpty()) this.start=this.end=node;
else
{
this.end.next=node;
this.end=node;
}
this.size++;
}
public int remove()
{
int num=this.start.num;
this.start=this.start.next;
this.size--;
return num;
}
public void clear()
{
this.start=this.end=null;
this.size=0;
}
public static void main(String args[])
{
Queue2 queue;
queue=new Queue2();
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
