n=int(input())
if (n%2==1):
    n+=1
ans=0
for i in range(n,501,2):
    ans+=i
print(ans)