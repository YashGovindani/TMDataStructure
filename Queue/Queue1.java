import java.io.*;
class Queue1
{
public static void main(String args[])
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
int queue[],front,rear,ch,num;
queue=new int[10];
rear=0;
front=0;
ch=0;
while(true)
{
System.out.println("1. Add ro queue");
System.out.println("2. Remove from queue");
System.out.println("3. Exit");
System.out.print("Enter your choice : ");
try
{
ch=Integer.parseInt(br.readLine());
}catch(IOException ioException)
{
System.out.println(ioException.getMessage());
}catch(NumberFormatException nfe)
{
System.out.println(nfe.getMessage());
}
if(ch==1)
{
if(rear==10) System.out.println("Queue is full, cannot add more elements to queue");
else
{
System.out.print("Enter the number to add to queue : ");
try
{
queue[rear]=Integer.parseInt(br.readLine());
rear++;
System.out.println(queue[rear-1]+" added to queue");
}catch(IOException ioException)
{
System.out.println(ioException.getMessage());
}catch(NumberFormatException nfe)
{
System.out.println(nfe.getMessage());
}
}
}
if(ch==2)
{
if(rear==0) System.out.println("Queue is empty");
else
{
num=queue[front];
front++;
if(front==rear) front=rear=0;
System.out.println(num+" removed from queue");
}
}
if(ch==3) break;
}
}
}
