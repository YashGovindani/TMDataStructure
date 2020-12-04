def quickSort(x,lowerBound,upperBound):
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
            while x[e]<=x[lb] and e<ub: e+=1
            while x[f]>x[lb]: f-=1
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
x=[]
req=5
for i in range(req): x.append(int(input("Enter a number : ")))
quickSort(x,0,req-1)
for i in x: print(i)
