x=[]
for i in range(10): x.append(int(input("Enter a number : ")))
lb=0
m=10-1
ub=m
size=ub-lb+1
diff=size//2
while diff>=1:
    e=lb+diff
    while e<=ub:
        num=x[e]
        f=e-diff
        while f>=lb and x[f]>num:
            x[f+diff]=x[f]
            f-=diff
        x[f+diff]=num
        e+=diff
    diff//=2
for i in x: print(i