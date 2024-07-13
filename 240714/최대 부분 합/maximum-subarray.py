정답=-9999999
n=int(input())
수열=list(map(int,input().split()))
table=[[0 for _ in range(n)] for _ in range(n)]
for i in range(n):
    for j in range(i,n):
        table[i][j]=table[i][j-1]+수열[j]
        정답=max(정답,table[i][j])
print(정답)