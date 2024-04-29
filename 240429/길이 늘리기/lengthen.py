n,m=map(int,input().split())
lists=list(map(int,input().split()))
lists.sort()
for i in lists:
    if m>=i:
        m+=1
print(m)