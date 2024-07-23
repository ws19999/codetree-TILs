n,k=map(int,input().split())
lists=list(map(int,input().split()))
for _ in range(k):
    for i in range(n-1):
        if(lists[i]>lists[i+1]):
            lists[i],lists[i+1]=lists[i+1],lists[i]
for elem in lists:
    print(elem,end=' ')