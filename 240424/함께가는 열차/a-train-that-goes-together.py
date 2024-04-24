N=int(input())
cnt=1
lists=[]
for _ in range(N):
    a,b=map(int,input().split())
    lists.append(b)
speed=lists[-1]
for i in range(N-2,-1,-1):
    if(i<=speed):
        speed=i
        cnt+=1
print(cnt)