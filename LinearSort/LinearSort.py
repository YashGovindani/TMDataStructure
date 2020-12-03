def linearSort(x,comparator):
    m=len(x)
    oep=m-2
    iep=m-1
    e=0
    while e<=oep:
        f=e+1
        while f<=iep:
            if comparator(x[f],x[e])<0:
                g=x[e]
                x[e]=x[f]
                x[f]=g
            f+=1
        e+=1

def comparator(left,right): return left-right

x=[]
req=int(input("Enter your requirement : "))
for i in range(req): x.append(int(input("Enter a number : ")))
linearSort(x,comparator)
for i in range(req): print(x[i])
