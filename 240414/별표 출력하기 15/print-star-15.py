n=int(input())
for i in range(n*2,2,-2):
    for _ in range(i):
        print('*',end='')
    print()
for i in range(2,n*2+2,2):
    for _ in range(i):
        print('*',end='')
    print()