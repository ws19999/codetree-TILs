N=int(input())
lists=[[0 for _ in range(N)] for _ in range(N)]
x=-1
y=-1
num=-1
cnt=0
for i in range(N,0,-1):
    if(cnt%3==0):
        for j in range(i):
            x+=1
            y+=1
            num+=1
            lists[x][y]=num%10
    elif(cnt%3==1):
        for j in range(i):
            y-=1
            num+=1
            lists[x][y]=num%10
    elif(cnt%3==2):
        for j in range(i):
            x-=1
            num+=1
            lists[x][y]=num%10
    cnt+=1
for i in range(N):
    for j in range(i+1):
        print(lists[i][j],end=' ')
    print()