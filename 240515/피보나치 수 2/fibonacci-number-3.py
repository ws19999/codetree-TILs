s=[0,1]
n=int(input())
for i in range(n-1):
    s=[s[1],(sum(s))%1000000007]
print(s[1])