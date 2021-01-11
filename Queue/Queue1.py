queue=[]
for i in range(10): queue.append(0)
front=rear=0
while True:
    print("1. add")
    print("2. remove")
    print("3. Exit")
    ch=int(input("Enter your choice : "))
    if ch==1:
        if rear==10:
            print("Queue is full")
            continue
        num=int(input("Enter a number : "))
        queue[rear]=num
        rear+=1
        print(f"{num} added to queue")
    if ch==2:
        if rear==0:
            print("Queue is empty")
            continue
        num=queue[front]
        front+=1
        if front==rear: front=rear=0
        print(f"{num} removed from queue")
    if ch==3: break
