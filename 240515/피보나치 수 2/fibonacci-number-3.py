a=0
b=1
n=int(input())
for i in range(n-1):
    a,b=b,(a+b)%1000000007
print(b)