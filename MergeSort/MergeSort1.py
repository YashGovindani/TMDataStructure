req=10
x=[]
stack1=[]
stack2=[]
tmp=[]
for y in range(req):
    x.append(int(input("Enter a number : ")))
    stack1.append(0)
    stack2.append(0)
    tmp.append(0)
# merge sort logic starts
top1=req
top2=req
# push 0,req-1 to stack1
top1-=1
stack1[top1]=(0,req-1)
while top1!=req: # stack1 is not empty
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
while top2!=req: #stack2 is not empty
    # pop from stack2 in lb1,ub2
    lb1,ub2=stack2[top2]
    top2+=1
    ub1=(lb1+ub2)//2
    lb2=ub1+1
    # logic to merge starts
    lb3=lb1
    ub3=ub2
    i1=lb1
    i2=lb2
    i3=lb3
    while i1<=ub1 and i2<=ub2:
        if x[i1]<x[i2]:
            tmp[i3]=x[i1]
            i1+=1
        else:
            tmp[i3]=x[i2]
            i2+=1
        i3+=1
    while i1<=ub1:
        tmp[i3]=x[i1]
        i1+=1
        i3+=1
    while i2<=ub2:
        tmp[i3]=x[i2]
        i2+=1
        i3+=1
    # put back
    i3=lb3
    while i3<=ub3:
        x[i3]=tmp[i3]
        i3+=1
    # logic to merge ends
# merge sort logic ends
for y in x: print(y)
