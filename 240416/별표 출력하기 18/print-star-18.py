n=int(input())
for i in range(n-1,-1,-1):
    for _ in range(i):
        print('    ',end='')
    for _ in range(n-1-i):
        print('* * ',end='')
    print('*')