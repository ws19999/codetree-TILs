a,b=map(int,input().split())
table=[0 for _ in range(10001)]
table[1]=1
for i in range(2,b+1):
    if(table[i]==0):
        j=i+i
        while(j<=b):
            table[j]=1
            j+=i
sums=0
minn=-1
for i in range(b,a-1,-1):
    if(table[i]==0):
        sums+=i
        minn=i
if(sums==0):
    print(-1)
else:
    print(sums)
    print(minn)