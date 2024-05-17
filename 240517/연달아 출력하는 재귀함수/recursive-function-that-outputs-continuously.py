n=int(input())
def dfs(n):
    if(n<3):
        print(n,end=' ')
        return
    dfs(n//3)
    print(n,end=' ')
dfs(n)