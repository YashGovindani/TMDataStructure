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

def getLargest(ptr,lb,ub):
    largest=ptr[lb]
    y=lb+1
    while y<=ub:
        if ptr[y]>largest: largest=ptr[y]
        y+=1
    return largest

def getDigitCount(num):
    dc=1
    while num>9:
        num//=10
        dc+=1
    return dc

def spreadForRadixSort(ptr,lb,ub,e,f,queues):
    y=lb
    while y<=ub:
        num=ptr[y]
        i=(num%e)//f
        queues[i].add(num)
        y+=1

def collectForRadixSort(ptr,lb,queues):
    i=lb
    y=0
    while y<=9:
        while not queues[y].isEmpty():
            ptr[i]=queues[y].remove()
            i+=1
        y+=1

def radixSort(ptr,lb,ub):
    queues=[]
    for y in range(10): queues.append(Queue())
    y=lb-1
    i=lb
    while i<=ub:
        if ptr[i]<0:
            y+=1
            if y==i: ptr[y]*=-1
            else:
                num=ptr[y]
                ptr[y]=(-1)*ptr[i]
                ptr[i]=num
        i+=1
    if y>lb: radixSort(ptr,lb,y)
    e=lb
    f=y
    while e<=f:
        num=(-1)*ptr[e]
        ptr[e]=(-1)*ptr[f]
        ptr[f]=num
        e+=1
        f-=1
    if y==ub: return
    lb=y+1
    largest=getLargest(ptr,lb,ub)
    dc=getDigitCount(largest)
    e=10
    f=1
    k=1
    while k<=dc:
        spreadForRadixSort(ptr,lb,ub,e,f,queues)
        collectForRadixSort(ptr,lb,queues)
        e*=10
        f*=10
        k+=1

x=[]
for y in range(10): x.append(int(input("Enter a number : ")))
radixSort(x,1,9)
for y in x: print(y)
