N=int(input())
개발자들=[]
for _ in range(N):
    a,b=map(int,input().split())
    개발자들.append((a,b))
개발자들.sort()
최소거리=1000000
for i in range(N-1):
    if(개발자들[i][1]+개발자들[i+1][1]==1):
        최소거리=min(최소거리,개발자들[i+1][0]-개발자들[i][0]-1)
정답=0
for i in range(N):
    if(i==0 and 개발자들[i][1]==1):
        정답+=1
    elif (개발자들[i][1]==1 and 개발자들[i][0]-개발자들[i-1][0]>최소거리):
        정답+=1
print(정답)