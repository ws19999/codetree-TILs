n=int(input())
lists=list(map(int,input().split()))
lists.sort(reverse=True);
ans=0
for i in range(n):
    if((i+1)%3!=0):
        ans+=lists[i]
print(ans)