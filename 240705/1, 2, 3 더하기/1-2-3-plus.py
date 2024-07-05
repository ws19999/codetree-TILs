n=int(input())
방법=0
def dfs(num):
    global 방법
    if(num==0):
        방법+=1
        return
    elif(num<0):
        return
    dfs(num-1)
    dfs(num-2)
    dfs(num-3)
dfs(n)
print(방법)