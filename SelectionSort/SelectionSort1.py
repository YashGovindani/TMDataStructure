x=[]
req=5
for i in range(req): x.append(int(input("Enter a number : ")))
oep=req-2
iep=req-1
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
for i in x: print(i)
