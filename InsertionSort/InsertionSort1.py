x=[]
req=5
m=req-1
for i in range(req): x.append(int(input("Enter a number : ")))
e=1
while e<=m:
    num=x[e]
    f=e-1
    while f>=0 and x[f]>num:
        x[f+1]=x[f]
        f-=1
    x[f+1]=num
    e+=1
for i in x: print(i)
