n=int(input())
table=[1,1]
for i in range(2,n+1):
    table.append(table[i-2]+table[i-1]+1)
print(table[i]%1000000007)