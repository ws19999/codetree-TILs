n=int(input())
lists=list(map(int,input().split()))
lists.sort()
for i in range(n-1):
    lists[n-1]=lists[i]/2+lists[n-1]
print(f'{lists[n-1]:.1f}')