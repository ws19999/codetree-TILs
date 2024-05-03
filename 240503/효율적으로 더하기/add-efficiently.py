n=int(input())
lists=list(map(int,input().split()))
lists.sort()
sums=0
ans=0
for elem in lists:
    sums+=elem
    ans+=sums
print(ans)