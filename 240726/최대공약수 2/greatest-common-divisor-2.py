from math import gcd
n=int(input())
수들=list(map(int,input().split()))
answer=0
for i in range(n):
    for j in range(i+1,n):
        answer+=gcd(수들[i],수들[j])
print(answer)