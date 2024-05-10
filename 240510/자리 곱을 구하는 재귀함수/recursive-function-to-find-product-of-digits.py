a,b,c=map(int,input().split())
n=a*b*c
num=1
while(n>0):
    if(n%10!=0):
        num*=(n%10)
    n//=10
print(num)