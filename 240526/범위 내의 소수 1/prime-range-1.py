a,b=map(int,input().split())
if(a==1):
    a+=1
minn=0
sums=0
for i in range(b,a-1,-1):
    prime=True
    for j in range(2,i):
        if(i%j==0):
            prime=False
            break
    if(prime):
        minn=i
        sums+=i
print(sums,minn)