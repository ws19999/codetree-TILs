n=int(input())
lists=list(map(int,input().split()))
minn=100000
for i in lists:
    if(minn>i):
        minn=i
for i in range(1,minn+1):
    a=True
    for j in lists:
        if(j%i!=0):
            a=False
    if(a):
        print(i)