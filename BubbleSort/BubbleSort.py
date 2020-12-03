def bubbleSort(x,comparator):
    m=len(x)-2
    while m>=0:
        e=0
        f=1
        while e<=m:
            if comparator(x[f],x[e])<0:
                g=x[e]
                x[e]=x[f]
                x[f]=g
            e+=1
            f+=1
        m-=1

def comparator(left,right):
    return left-right

x=[]
req=int(input("Enter your requirement : "))
for y in range(req): x.append(int(input("Enter a number : ")))
bubbleSort(x,comparator)
for y in x: print(y)
