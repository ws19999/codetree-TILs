n=int(input())
table=[1000000 for _ in range(n+1)]
table[1]=0
for i in range(2,n+1):
    if(i%3==0):
        table[i]=min(table[i],table[i//3]+1)
    if(i%2==0):
        table[i]=min(table[i],table[i//2]+1)
    table[i]=min(table[i],table[i-1]+1)
print(table[n])