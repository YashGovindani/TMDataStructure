class Stack<T>
{
class StackNode
{
public T data;
public StackNode next;
}
private StackNode top;
private int size;
public Stack()
{
this.top=null;
this.size=0;
}
public void push(T data)
{
StackNode t;
t=new StackNode();
t.data=data;
t.next=this.top;
this.top=t;
this.size++;
}
public T pop()
{
T dataToReturn=this.top.data;
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
class Student
{
private int rollNumber;
public Student()
{
this.rollNumber=0;
}
public void setRollNumber(int rollNumber)
{
this.rollNumber=rollNumber;
}
public int getRollNumber()
{
return this.rollNumber;
}
}
class StackTester
{
public static void main(String args[])
{
Stack <Student>stack;
stack=new Stack<>();
Student student;
for(int i=0;i<=9;i++)
{
student=new Student();
student.setRollNumber(i);
stack.push(student);
}
while(!stack.isEmpty()) System.out.println(stack.pop().getRollNumber());
}
}
