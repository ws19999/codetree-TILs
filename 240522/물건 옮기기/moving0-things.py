table=[2 for _ in range(11)]
ans=0
n=int(input())
for _ in range(n):
    num,pos=map(int,input().split())
    if(table[num]==2):
        table[num]=pos
    elif(table[num]!=pos):
        table[num]=pos
        ans+=1
print(ans)