n=int(input())
table=[0,2]
def dfs(cnt):
    if(cnt==1):
        print(table[1],end=' ')
    else:
        dfs(cnt-1)
        table.append(table[cnt//2]+table[cnt-1])
        print(table[cnt],end=' ')
        
dfs(n)