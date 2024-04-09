n,m=map(int,input().split())
num=0
for _ in range(n):
    for _ in range(m):
        num+=1
        print(num,end=' ')
    print()