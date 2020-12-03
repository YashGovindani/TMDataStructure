x=[]
req=5
for i in range(req): x.append(int(input("Enter a number : ")))
oep=req-2
iep=req-1
e=0
while e<=oep:
    f=e+1
    while f<=iep:
        if x[f]<x[e]:
            g=x[e]
            x[e]=x[f]
            x[f]=g
        f+=1
    e+=1
for i in range(req): print(x[i])
