N=int(input())
lists=[]
for _ in range(N):
    a,b=map(int,input().split())
    lists.append((a,b))
lists.sort()
t=0
for i in lists:
    if i[0]<t:
        t+=i[1]
    else:
        t=i[0]+i[1]
print(t)