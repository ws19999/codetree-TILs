dx=[-1,-1,-1,0,1,1,1,0]
dy=[-1,0,1,1,1,0,-1,-1]
n=int(input())
map=[input() for _ in range(n)]
table=[[0 for _ in range(n)] for _ in range(n)]
for i in range(n):
    for j in range(n):
        if(map[i][j]=='*'):
            for k in range(8):
                nextx=i+dx[k]
                nexty=j+dy[k]
                if(nextx>=0 and nextx<n and nexty>=0 and nexty<n):
                    table[nextx][nexty]+=1
inputs=[input() for _ in range(n)]
for i in range(n):
    for j in range(n):
        if(inputs[i][j]=='x'):
            print(table[i][j],end='')
        else:
            print('.',end='')
    print()