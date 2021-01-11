def shellSort(x,lb,ub):
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

x=[]
for i in range(6): x.append(int(input("Enter a number : ")))
shellSort(x,1,5)
for i in x: print(i)