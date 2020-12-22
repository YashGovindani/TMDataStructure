def merge(x,lb1,ub1,lb2,ub2):
    size1=ub1-lb1+1
    size2=ub2-lb2+1
    size3=size1+size2
    lb3=0
    ub3=size3-1
    i1=lb1
    i2=lb2
    tmp=[]
    while i1<=ub1 and i2<=ub2:
        if x[i1]<x[i2]:
            tmp.append(x[i1])
            i1+=1
        else:
            tmp.append(x[i2])
            i2+=1
    while i1<=ub1:
        tmp.append(x[i1])
        i1+=1
    while i2<=ub2:
        tmp.append(x[i2])
        i2+=1
    # put back
    i3=lb3
    i1=lb1
    while i1<=ub1:
        x[i1]=tmp[i3]
        i1+=1
        i3+=1
    i2=lb2
    while i2<=ub2:
        x[i2]=tmp[i3]
        i2+=1
        i3+=1

def mergeSort(x,lowerBound,upperBound):
    size=upperBound-lowerBound+1
    stack1=[]
    stack2=[]
    for y in range(size):
        stack1.append(0)
        stack2.append(0)
    top1=size
    top2=size
    # push lowerBound,upperBound on stack1
    top1-=1
    stack1[top1]=(lowerBound,upperBound)
    while top1!=size: # stack1 is not empty
        # pop from stack1 in a,b
        a,b=stack1[top1]
        top1+=1
        # push a,b on stack2
        top2-=1
        stack2[top2]=(a,b)
        # calculate mid
        mid=(a+b)//2
        if a<mid:
            # push a,mid on stack1
            top1-=1
            stack1[top1]=(a,mid)
        if mid+1<b:
            # push mid+1,b on stack1
            top1-=1
            stack1[top1]=(mid+1,b)
    while top2!=req: # stack2 is not empty
        # pop from stack2 in lb1,ub2
        lb1,ub2=stack2[top2]
        top2+=1
        ub1=(lb1+ub2)//2
        lb2=ub1+1
        merge(x,lb1,ub1,lb2,ub2)

x=[]
req=int(input("Enter your requirement : "))
for y in range(req): x.append(int(input("Enter a number : ")))
mergeSort(x,0,req-1)
for y in x: print(y)
