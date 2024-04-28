a,b=map(int,input().split())
if(b<a):
    a,b=b,a
minn=0
for i in range(1,a+1):
    if(b%i==0 and a%i==0):
        minn=i
print(minn,end=' ')
print(a*b//minn)