def toMaxHeap(x,lb,ub):
    diff=lb
    ub-=lb
    lb=0
    y=lb+1
    while y<=ub:
        ci=y
        while ci>lb:
            ri=(ci-1)//2
            if x[ci+diff]>x[ri+diff]:
                g=x[ci+diff]
                x[ci+diff]=x[ri+diff]
                x[ri+diff]=g
                ci=ri
            else: break
        y+=1
def adjustHeap(x,lb,ub):
    diff=lb
    ub-=lb
    lb=0
    y=ub
    ri=lb
    while ri<y:
        lci=2*ri+1
        if lci>y: break
        rci=lci+1
        if rci>y: swi=lci
        else:
            if x[lci+diff]>x[rci+diff]: swi=lci
            else: swi=rci
        if x[swi+diff]>x[ri+diff]:
            g=x[swi+diff]
            x[swi+diff]=x[ri+diff]
            x[ri+diff]=g
            ri=swi
        else: break
def heapSort(x,lb,ub):
    diff=lb
    ub-=lb
    lb=0
    toMaxHeap(x,lb+diff,ub+diff)
    y=ub
    while y>lb:
        g=x[lb+diff]
        x[lb+diff]=x[y+diff]
        x[y+diff]=g
        y-=1
        adjustHeap(x,lb+diff,y+diff)

x=[]
req=int(input("Enter your requirement : "))
for y in range(req): x.append(int(input("Enter a number : ")))
heapSort(x,1,req-1)
for y in x: print(y)
