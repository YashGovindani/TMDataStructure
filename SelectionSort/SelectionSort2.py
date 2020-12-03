def selectionSort(x):
    size=len(x)
    oep=size-2
    iep=size-1
    e=0
    while e<=oep:
        si=e
        f=e+1
        while f<=iep:
            if x[f]<x[si]: si=f
            f+=1
        g=x[e]
        x[e]=x[si]
        x[si]=g
        e+=1
x=[]
req=5
for i in range(req): x.append(int(input("Enter a number : ")))
selectionSort(x)
for i in x: print(i)
