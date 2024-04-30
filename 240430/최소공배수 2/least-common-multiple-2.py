a,b=map(int,input().split())
temp=1
start=min(a,b)
for i in range(start,1,-1):
    if(a%i==0 and b%i==0):
        a//=i
        b//=i
        temp*=i
print(temp*a*b)