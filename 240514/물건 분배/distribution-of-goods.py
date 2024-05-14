ans=0
n,k=map(int,input().split())
lists=[]
for _ in range(k):
    a,b=map(int,input().split())
    lists.append(a*b)
lists.sort(reverse=True)
while(n>0):
    n-=lists[ans]
    ans+=1
print(ans)