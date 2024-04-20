def dfs(num):
    if(num==0):
        return
    print('Coding is my favorite hobby!')
    dfs(num-1)
n=int(input())
dfs(n)