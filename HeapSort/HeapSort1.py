x=[]
req=6
m=req-1
for i in range(req): x.append(int(input("Enter a number : ")))
# logic to convert array to heap
y=1
while y<=m:
    ci=y
    while ci>0:
        ri=(ci-1)//2
        if x[ci]>x[ri]:
            g=x[ci]
            x[ci]=x[ri]
            x[ri]=g
            ci=ri
        else: break
    y+=1
# implementing heap sort
y=m
while y>0:
    g=x[0]
    x[0]=x[y]
    x[y]=g
    y-=1
    # logic to adjust heap
    ri=0
    while ri<y:
        lci=2*ri+1
        if lci>y: break
        rci=lci+1
        if rci>y: swi=lci
        else:
            if x[lci]>x[rci]: swi=lci
            else: swi=rci
        if x[swi]>x[ri]:
            g=x[swi]
            x[swi]=x[ri]
            x[ri]=g
            ri=swi
        else: break
for i in x: print(i)
