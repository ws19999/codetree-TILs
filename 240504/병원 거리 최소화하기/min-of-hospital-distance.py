import sys
dx,dy=[-1,0,1,0],[0,1,0,-1]
n,m=map(int,input().split())
table=[list(map(int,input().split())) for _ in range(n)]
lists=[]
homes=[]
for i in range(n):
    for j in range(n):
        if table[i][j]==2:
            lists.append((i,j))
        elif table[i][j]==1:
            homes.append((i,j))
dfslist=[]
ans=sys.maxsize
def dfs(cnt,pos):
    global m,ans
    if cnt==m:
        tempans=0
        for home in homes:
            temp=sys.maxsize
            for chickenshop in dfslist:
                temp=min(temp,abs(home[0]-chickenshop[0])+abs(home[1]-chickenshop[1]))
            tempans+=temp
        ans=min(ans,tempans)
        return
    for i in range(pos+1,len(lists)):
        dfslist.append((lists[i][0],lists[i][1],0))
        dfs(cnt+1,i)
        dfslist.pop()
dfs(0,-1)
print(ans)