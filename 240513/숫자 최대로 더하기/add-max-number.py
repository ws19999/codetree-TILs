n=int(input())
lists=list(map(int,input().split()))
lists.sort()
for i in range(n-1):
    lists[n-i-1]=lists[0]/2+lists[n-i-1]
    del lists[0]
    lists.sort()
print(f'{lists[0]:.1f}')