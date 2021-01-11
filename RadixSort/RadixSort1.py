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

x=[]
queues=[]
for y in range(10): queues.append(Queue())
for y in range(10): x.append(int(input("Enter a number : ")))
# logic to find largest
largest=x[0]
for y in x:
    if y>largest: largest=y
# logic to find digit count
dc=1
num=largest
while num>9:
    num//=10
    dc+=1
# logic to sort
e=10
f=1
k=1
while k<=dc:
    # spread
    y=0
    while y<=9:
        num=x[y]
        i=(num%e)//f
        queues[i].add(num)
        y+=1
    #collect
    y=0
    i=0
    while y<=9:
        while not queues[y].isEmpty():
            x[i]=queues[y].remove()
            i+=1
        y+=1
    e*=10
    f*=10
    k+=1
for y in x: print(y)
