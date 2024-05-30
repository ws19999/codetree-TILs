n,m=map(int,input().split())
s=0
ans=1
lists=list(map(int,input().split()))
for i in range(n):
    weight=lists[i]
    if(s+weight>m):
        ans+=1
        s=weight
    else:
        s+=weight
print(ans)