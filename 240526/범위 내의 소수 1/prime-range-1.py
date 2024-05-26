lists=[1 for _ in range(1000001)]
lists[1]=0
for i in range(2,1000001):
    if(lists[i]==1):
        j=i+i
        while(j<=1000000):
            lists[j]=0
            j+=i
a,b=map(int,input().split())
ans=0
minn=0
for i in range(b,a-1,-1):
    if(lists[i]):
        ans+=i
        minn=i
print(ans,minn)