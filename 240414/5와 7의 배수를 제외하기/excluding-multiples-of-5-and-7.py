n=int(input())
lists=list(map(int,input().split()))
sums=0
cnt=0
for elem in lists:
    if(elem%5!=0 and elem%7!=0):
        sums+=elem
        cnt+=1
print(sums)
print(f'{sums/cnt:.1f}')