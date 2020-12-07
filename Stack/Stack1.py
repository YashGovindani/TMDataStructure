class StackNode:
    def __init__(self):
        self.data=0
        self.next=None
top=0
def push(num):
    global top
    t=StackNode()
    t.data=num
    t.next=top
    top=t
def pop():
    global top
    data=top.data
    top=top.next
    return data
def isEmpty():
    global top
    return top==0
for i in range(10): push(i)
while not isEmpty(): print(pop())
