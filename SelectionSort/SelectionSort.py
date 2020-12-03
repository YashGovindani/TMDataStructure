def selectionSort(x,comparator):
    size=len(x)
    oep=size-2
    iep=size-1
    e=0
    while e<=oep:
        si=e
        f=e+1
        while f<=iep:
            if comparator(x[f],x[si])<0: si=f
            f+=1
        g=x[e]
        x[e]=x[si]
        x[si]=g
        e+=1

def comparator(left,right): return left-right

x=[]
req=int(input("Enter your requirement : "))
for i in range(req): x.append(int(input("Enter a number : ")))
selectionSort(x,comparator)
for i in x: print(i)
