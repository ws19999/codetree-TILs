n=int(input())
lists=list(map(int,input().split()))
seq=0
ans=0
lists.sort()
for i in range(n-1,-1,-1):
    if(lists[i]-seq>0):
        ans+=lists[i]-seq
    seq+=1
print(ans)