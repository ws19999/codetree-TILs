N=int(input())
m=int(input())
map=[[0 for _ in range(N)] for _ in range(N)]
x=N//2
y=N//2
num=1
a=0
b=0
i=1
while(True):
    if(i%2==0):
        for j in range(i):
            map[x][y]=num
            if(num==m):
                a=x+1
                b=y+1
            num+=1
            x+=1
        for j in range(i):
            map[x][y]=num
            if(num==m):
                a=x+1
                b=y+1
            num+=1
            y-=1
    else:
        for j in range(i):
            map[x][y]=num
            if(num==m):
                a=x+1
                b=y+1
            num+=1
            x-=1
        if(num==N*N+1):
            break
        for j in range(i):
            map[x][y]=num
            if(num==m):
                a=x+1
                b=y+1
            num+=1
            y+=1
    i+=1
for i in range(N):
    for j in range(N):
        print(map[i][j],end=' ')
    print()
print(a,b)