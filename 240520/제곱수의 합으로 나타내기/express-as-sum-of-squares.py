n=int(input())
ans=5
def dfs(depth,num):
    global n,ans
    if(depth>=ans):
        return
    for i in range(1,n+1):
        num+=i*i
        if(num==n):
            ans=min(ans,depth)
            break
        if(num>n):
            break
        dfs(depth+1,num)
        num-=i*i
dfs(1,0)
print(ans)