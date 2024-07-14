N=int(input())
mixx=list(map(int,input().split()))
lists=list(map(int,input().split()))
nextlists=[0 for _ in range(N)]
for _ in range(3):
    for i in range(N):
        nextlists[i]=lists[mixx[i]-1]
    for i in range(N):
        lists[i]=nextlists[i]
for elem in lists:
    print(elem)