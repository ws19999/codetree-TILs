check=[0 for _ in range(1000001)]
numbers=[]
N=int(input())
seq=[]
for _ in range(N):
    num=int(input())
    if(check[num]==0):
        check[num]=1
        numbers.append(num)
    seq.append(num)
ans=0
for num in numbers:
    temp=0
    last=0
    for i in range(0,N):
        if(seq[i]==num):
            continue
        if(last==seq[i]):
            temp+=1
            ans=max(ans,temp)
        else:
            ans=max(ans,temp)
            temp=1
            last=seq[i]
print(ans)