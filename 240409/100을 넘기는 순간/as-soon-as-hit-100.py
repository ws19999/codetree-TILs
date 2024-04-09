n=int(input())
lists=list(map(int,input().split()))
sums=0
avg=0
cnt=0
for i in range(n):
    sums+=lists[i]
    cnt+=1
    if(lists[i]>=100):
        print(sums)
        print(f'{sums/cnt:.1f}')
        break