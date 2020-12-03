def bubbleSort(x):
    m=len(x)-2
    while m>=0:
        e=0
        f=1
        while e<=m:
            if x[f]<x[e]:
                g=x[e]
                x[e]=x[f]
                x[f]=g
            e+=1
            f+=1
        m-=1

x=[]
req=int(input("Enter your requirement : "))
for y in range(req): x.append(int(input("Enter a number : ")))
bubbleSort(x)
for y in x: print(y)