def quickSort(x,lowerBound,upperBound,comparator):
    size=upperBound-lowerBound+1
    lbStack=[]
    ubStack=[]
    for i in range(size):
        lbStack.append(0)
        ubStack.append(0)
    top=size
    top-=1
    lbStack[top]=lowerBound
    ubStack[top]=upperBound
    while top!=size:
        lb=lbStack[top]
        ub=ubStack[top]
        top+=1
        e=lb
        f=ub
        while e<f:
            while comparator(x[e],x[lb])<=0 and e<ub: e+=1
            while comparator(x[f],x[lb])>0: f-=1
            if e<f:
                g=x[e]
                x[e]=x[f]
                x[f]=g
            else:
                g=x[f]
                x[f]=x[lb]
                x[lb]=g
                pp=f
        if pp+1<ub:
            top-=1
            lbStack[top]=pp+1
            ubStack[top]=ub
        if lb<pp-1:
            top-=1
            lbStack[top]=lb
            ubStack[top]=pp-1
def comparator(left,right): return left-right
x=[]
req=int(input("Enter your requirement : "))
for i in range(req): x.append(int(input("Enter a number : ")))
quickSort(x,0,req-1,comparator)
for i in x: print(i)
