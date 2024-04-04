n=int(input())
lists=list(map(int,input().split()))
k=int(input())
mul=0
div=0
for i in range(n):
    if(lists[i]%k==0):
        mul+=lists[i]
    if(k%lists[i]==0):
        div+=lists[i]
print(div)
print(mul)