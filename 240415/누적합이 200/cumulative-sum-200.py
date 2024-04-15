n=int(input())
lists=list(map(int,input().split()))
sums=0
cnt=0
for elem in lists:
    sums+=elem
    cnt+=1
    if(sums>200):
        break
print(sums)
print(f'{sums/cnt:.1f}')