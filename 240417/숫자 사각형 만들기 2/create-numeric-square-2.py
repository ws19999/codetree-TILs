n,m=map(int,input().split())
num=n*m
for _ in range(n):
    for _ in range(m):
        print(num,end=' ')
        num-=1
    print()