a,b=map(int,input().split())
최소공배수=1
최대공약수=1
for i in range(min(a,b),1,-1):
    if(a%i==0 and b%i==0):
        a//=i
        b//=i
        최대공약수*=i
print(최대공약수,a*b*최대공약수)