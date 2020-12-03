def insertionSort(x,comparator):
    m=len(x)-1
    e=1
    while e<=m:
        num=x[e]
        f=e-1
        while f>=0 and comparator(x[f],num)>0:
            x[f+1]=x[f]
            f-=1
        x[f+1]=num
        e+=1
def comparator(left,right): return left-right
x=[]
req=int(input("Enter your requirement : "))
m=req-1
for i in range(req): x.append(int(input("Enter a number : ")))
insertionSort(x,comparator)
for i in x: print(i)
