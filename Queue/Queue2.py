class Queue:
    class QueueNode:
        def __init__(self):
            self.data=None
            self.next=None
    def __init__(self):
        self.start=None
        self.end=None
        self.size=0
    def isEmpty(self):
        return self.size==0
    def add(self,data):
        if data==None: return
        node=Queue.QueueNode()
        node.data=data
        if self.start==None:
            self.start=self.end=node
        else:
            self.end.next=node
            self.end=node
        self.size+=1
    def remove(self):
        if self.isEmpty(): return
        data=self.start.data
        self.start=self.start.next
        if self.start==None: self.end=None
        self.size-=1
        return data
    def clear(self):
        self.start=self.end=None
        self.size=0

queue=Queue()
while True:
    print("1. Add")
    print("2. Remove")
    print("3. Exit")
    ch=int(input("Enter your choice : "))
    if ch==1:
        queue.add(int(input("Enter a number : ")))
    if ch==2:
        if queue.isEmpty(): print("Queue is empty")
        else: print(queue.remove(),"removed from queue")
    if ch==3: break
queue.clear()
