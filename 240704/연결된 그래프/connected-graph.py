from collections import deque
dq=deque()
dq.append(1)
check=[False for _ in range(101)]
n,m=map(int,input().split())
lists=[[] for _ in range(n+1)]
for _ in range(m):
    a,b=map(int,input().split())
    lists[a].append(b)
    lists[b].append(a)
answer=0
check[1]=True
while(dq):
    num=dq[0]
    dq.popleft()
    for i in lists[num]:
        if not (check[i]):
            check[i]=True
            dq.append(i)
            answer+=1
print(answer)