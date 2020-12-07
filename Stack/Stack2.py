class StackNode:
    def __init__(self):
        self.data=0
        self.next=None
class Stack:
    def __init__(self):
        self.top=None
        self.size=0
    def push(self,data):
        t=StackNode()
        t.data=data
        t.next=self.top
        self.top=t
        self.size+=1
    def pop(self):
        data=self.top.data
        self.top=self.top.next
        self.size-=1
        return data
    def isEmpty(self):
        #return self.top==None
        return self.size==0
stack=Stack()
for i in range(10): stack.push(i)
print(stack.size)
while not stack.isEmpty(): print(stack.pop())
