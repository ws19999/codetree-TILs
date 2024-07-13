최소=1000000
def dfs(num,cnt):
    global 최소
    if(num==1):
        최소=min(최소,cnt)
        return
    if(num%3==0):
        dfs(num//3,cnt+1)
    if(num%2==0):
        dfs(num//2,cnt+1)
    dfs(num-1,cnt+1)
n=int(input())
dfs(n,0)
print(최소)