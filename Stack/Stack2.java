class Stack2
{
class StackNode
{
public int data;
public StackNode next;
}
private StackNode top;
private int size;
public Stack2()
{
this.top=null;
this.size=0;
}
public void push(int num)
{
StackNode t;
t=new StackNode();
t.data=num;
t.next=this.top;
this.top=t;
this.size++;
}
public int pop()
{
int dataToReturn=this.top.data;
this.top=this.top.next;
this.size--;
return dataToReturn;
}
public boolean isEmpty()
{
// return this.top==null;
return this.size==0;
}
}
class Stack2Tester
{
public static void main(String args[])
{
Stack2 stack;
stack=new Stack2();
for(int i=0;i<=9;i++) stack.push(i);
while(!stack.isEmpty()) System.out.println(stack.pop());
}
}
