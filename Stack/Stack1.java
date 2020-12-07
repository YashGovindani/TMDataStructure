class StackNode
{
public int data;
public StackNode next;
}
class Stack1
{
public static StackNode top=null;
public static void push(int num)
{
StackNode t;
t=new StackNode();
t.data=num;
t.next=top;
top=t;
}
public static int pop()
{
int data;
data=top.data;
top=top.next;
return data;
}
public static boolean isEmpty()
{
return top==null;
}
public static void main(String args[])
{
int i;
for(i=0;i<=9;i++) push(i);
while(!isEmpty()) System.out.println(pop());
}
}
