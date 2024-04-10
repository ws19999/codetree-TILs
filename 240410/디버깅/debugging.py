ans=4
n,m,h=map(int,input().split())
ladder=[[0 for _ in range(n+1)] for _ in range(h+1)]
def dfs(depth,last):
    global ans,n,m,h,ladder
    if(depth==ans):
        return
    p=True
    for i in range(1,n+1):
        num=i
        for j in range(1,h+1):
            if (ladder[j][num-1]):
                num-=1
            elif (ladder[j][num]):
                num+=1
        if(num!=i):
            p=False
            break
    if(p):
        ans=min(ans,depth)
        return
    if(depth==3):
        return;
    for i in range(last,h+1):
        for j in range(1,n):
            if (ladder[i][j]==0 and ladder[i][j-1]==0):
                ladder[i][j]=1
                dfs(depth+1,i)
                ladder[i][j]=0
for i in range(m):
    a,b=map(int,input().split())
    ladder[a][b]=1
dfs(0,1)
print(-1 if ans==4 else ans)